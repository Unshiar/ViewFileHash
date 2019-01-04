#include <QCoreApplication>
#include <iostream>
#include <QFile>

#include "ConsoleHelper.h"
#include "MessageHelper.h"
#include "HashHelper.h"
#include "common.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ConsoleHelper::SetArguments(argc, argv);

    //Не введено ни одного параметра
    if(ConsoleHelper::argumentsList.size() <= 1)
    {
        std::cout << MessageHelper::messageNoArguments << std::endl;
        std::cout << MessageHelper::messageTypeHelp << std::endl;
        return -1;
    }

    //Был ли введен аргумент = --help
    if(ConsoleHelper::FindArgument_Help(ConsoleHelper::argumentsList))
    {
        std::cout << MessageHelper::messageHelp << std::endl;
        return -1;
    }

    //Проверка файла, по введенному имени
    QFile file(ConsoleHelper::GetArgument_FileName(ConsoleHelper::argumentsList));

    if(!file.exists())
    {
        std::cout << MessageHelper::messageNoFile << file.fileName().toStdString() << std::endl;
        return -1;
    }

    //Был ли введен неверный аргумент-алгоритм
    QString wrongArgument = ConsoleHelper::FindWrongArgument(ConsoleHelper::argumentsList);

    if(!wrongArgument.isEmpty())
    {
        std::cout << MessageHelper::messageWrongArgument << wrongArgument.toStdString() << std::endl << std::endl;
        std::cout << MessageHelper::messageHelp << std::endl;
        return -1;
    }

    //Просчитываем хеш файла по выбранным алгоритмам
    std::vector<QString> selectedAlgoritms = ConsoleHelper::GetArguments_Algoritms(ConsoleHelper::argumentsList);
    //Если пользователь не задал ни одного алгоритма, то по-умолчанию выводим md5
    if(selectedAlgoritms.size() == 0)
        selectedAlgoritms.push_back(CommonValues::hashAlgoritms.at(1));

    std::cout << MessageHelper::messageForFile << file.fileName().toStdString() << std::endl << std::endl;

    //Откроем файл для чтения данных
    file.open(QIODevice::ReadOnly);

    for(size_t i = 0; i < selectedAlgoritms.size(); ++i)
    {
        std::cout << selectedAlgoritms.at(i).toStdString() << ":\t";

        //Зададим алгоритм хеша
        QCryptographicHash hash(HashHelper::GetCryptographicAlgoritm(selectedAlgoritms.at(i)));
        //Передадим файл для подсчета хеша, по текущему алогоритму
        if(!hash.addData(&file))
        {
            std::cout << MessageHelper::messageCantReadFile << std::endl;
            break;
        }
        //Если файл удачно получен, выводим результат, для текущего алгортма
        std::cout << hash.result().toHex().toStdString() << std::endl;
        //Сброс для последующих вычислений
        hash.reset();
        //Открытый файл будем читать опять сначало
        if(!file.seek(0))
        {
            std::cout << MessageHelper::messageCantReadFile << std::endl;
            break;
        }
    }

    //Закроем файл
    file.close();

    //Конец
    return 0;

    return a.exec();
}

