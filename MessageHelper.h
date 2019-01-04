#ifndef MESSAGEHELPER_H
#define MESSAGEHELPER_H

namespace MessageHelper {

const char messageNoArguments[] = "Error: not enough arguments\n";

const char messageWrongArgument[] = "You type wrong argument: ";

const char messageNoFile[] = "Can't find file: ";

const char messageCantReadFile[] = "Can't read file\n";

const char messageForFile[] = "For file:\n";

const char messageTypeHelp[] = "Type vfhash --help for help\n";

const char messageHelp[] = "Usage: vfhash <filename> <algoritms> \n"
                           "filename\t- file what you want see hash\n"
                           "algoritms\t- hash algoritms ( md5 md4 sha1 sha224 sha256 sha384 sha512 sha3_224 sha3_256 sha3_384 sha3_512 keccak_224 keccak_256 keccak_384 keccak_512 )\n\n"
                           "For example:\n"
                           "vfhash file1.txt md4 md5\n"
                           "or\n"
                           "vfhash file1.txt sha1\n";
}

#endif // MESSAGEHELPER_H
