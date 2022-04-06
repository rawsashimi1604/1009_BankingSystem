#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#define CIPHER_KEY 3

class Encrypter
{

private:
    char encryptChar(char ch);
    char decryptChar(char ch);

public:
    Encrypter();

    std::string hash(std::string input);
    std::string encryptASCII(std::string);
    std::string decryptASCII(std::string);
};

#endif // ENCRYPTER_H
