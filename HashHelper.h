#ifndef HASHHELPER_H
#define HASHHELPER_H

#include <QString>
#include <QCryptographicHash>

#include "common.h"

namespace HashHelper {

QCryptographicHash::Algorithm GetCryptographicAlgoritm(const QString &algoritm)
{
    QCryptographicHash::Algorithm result = QCryptographicHash::Md5;

    if(algoritm == "md4")
        result = QCryptographicHash::Md4;
    if(algoritm == "md5")
        result = QCryptographicHash::Md5;
    if(algoritm == "sha1")
        result = QCryptographicHash::Sha1;
    if(algoritm == "sha224")
        result = QCryptographicHash::Sha224;
    if(algoritm == "sha256")
        result = QCryptographicHash::Sha256;
    if(algoritm == "sha384")
        result = QCryptographicHash::Sha384;
    if(algoritm == "sha512")
        result = QCryptographicHash::Sha512;
    if(algoritm == "sha3_224")
        result = QCryptographicHash::Sha3_224;
    if(algoritm == "sha3_256")
        result = QCryptographicHash::Sha3_256;
    if(algoritm == "sha3_384")
        result = QCryptographicHash::Sha3_384;
    if(algoritm == "sha3_512")
        result = QCryptographicHash::Sha3_512;
    if(algoritm == "keccak_224")
        result = QCryptographicHash::Keccak_224;
    if(algoritm == "keccak_256")
        result = QCryptographicHash::Keccak_256;
    if(algoritm == "keccak_384")
        result = QCryptographicHash::Keccak_384;
    if(algoritm == "keccak_512")
        result = QCryptographicHash::Keccak_512;

    return result;
}

}

#endif // HASHHELPER_H
