#include <iostream>
#include <string>

//Change the cipher key as necessary
#define CIPHER_KEY 3

char encryptch(char ch) {
    ch = ch + CIPHER_KEY;
    if (ch > 97){
        if (ch > 122) {
            ch = ch - 122;
            ch = ch + 96;
            return ch;
        } else {
            return ch;
        }
    } else {
        if (ch> 90) {
            ch = ch - 90;
            ch = ch + 64;
            return ch;
        } else {
            return ch;
        }
    }
}

char decryptch(char ch) {
    ch = ch  - CIPHER_KEY;
    if (ch < 90) {
        if (ch < 65) {
            ch = ch - 65;
            ch = ch + 91;
            return ch;
        } else {
            return ch;
        }
    } else {
        if (ch < 97) {
            ch = ch - 97;
            ch = ch + 123;
            return ch;
        } else {
            return ch;
        }
    }
}

std::string encryptASCII(std::string plainTXT){
    std::string cipherTXT;
    int count = 0;
    while (plainTXT[count] != '\0'){
        cipherTXT += encryptch(plainTXT[count]);
        count++;
    }
    return cipherTXT;
}

std::string decryptASCII(std::string cipherTXT){
    std::string plainTXT;
    int count = 0;
    while (cipherTXT[count] != '\0'){
        plainTXT += decryptch(cipherTXT[count]);
        count++;
    }
    return plainTXT;
}

int main() {
    std::string test = "my name is Nyan Lin Htoo";
    std::cout << test << std::endl;
    std::cout << encryptASCII(test) << std::endl;
}
