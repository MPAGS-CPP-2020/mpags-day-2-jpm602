#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>

// Process text with Caesar cipher to encrypt/decrypt
std::string runCaesarCipher(
    bool encrypt,
    unsigned long key,
    std::string inputText
);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP