#ifndef COMMON_H
#define COMMON_H

#include <QString>

namespace CommonValues {

static const std::vector<QString> hashAlgoritms = {"md4",
                                                   "md5",
                                                   "sha1",
                                                   "sha224",
                                                   "sha256",
                                                   "sha384",
                                                   "sha512",
                                                   "sha3_224",
                                                   "sha3_256",
                                                   "sha3_384",
                                                   "sha3_512",
                                                   "keccak_224",
                                                   "keccak_256",
                                                   "keccak_384",
                                                   "keccak_512"
                                                  };
}

#endif // COMMON_H
