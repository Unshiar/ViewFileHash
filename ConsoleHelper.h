#ifndef CONSOLEHELPER_H
#define CONSOLEHELPER_H

#include <vector>
#include <QString>

#include "common.h"

namespace ConsoleHelper {

static std::vector<QString> argumentsList;

//Сохраняем аргументы введенные пользователем
void SetArguments(const int argc, char *argv[])
{
    argumentsList.clear();
    argumentsList.shrink_to_fit();

    for(int i = 0; i < argc; ++i)
        argumentsList.push_back(argv[i]);
}

//Найдем агрумент "--help" в введенных агрументах
bool FindArgument_Help(const std::vector<QString> &arguments)
{
    bool result = false;

    if(std::find(arguments.begin(), arguments.end(), "--help") != std::end(arguments))
            result = true;

    return result;
}

//Найдем неправильный агрумент в введенных агрументах
QString FindWrongArgument(const std::vector<QString> &arguments)
{
    QString result;

    for(size_t i = 2; i < arguments.size(); ++i)
        if(std::find(CommonValues::hashAlgoritms.begin(), CommonValues::hashAlgoritms.end(), arguments.at(i)) == std::end(CommonValues::hashAlgoritms))
        {
                result = arguments.at(i);
                break;
        }

    return result;
}

//Получить список хэш алгоритмов в введенных аргументах
const std::vector<QString> GetArguments_Algoritms(const std::vector<QString> &arguments)
{
    std::vector<QString> result;

    for(size_t i = 2; i < arguments.size(); ++i)
        result.push_back(arguments.at(i));

    return result;
}

//Получить имя файла в введенных параметрах
const QString GetArgument_FileName(const std::vector<QString> &arguments)
{
    QString result;

    if(arguments.size() <= 1)
        return result;

    result = arguments.at(1);

    return result;
}

}

#endif // CONSOLEHELPER_H
