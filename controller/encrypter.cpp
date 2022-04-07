#include "encrypter.h"

Encrypter::Encrypter()
{

}

Customer& Encrypter::encryptCustomer(Customer &customer) {
    customer.firstName = encryptASCII(customer.firstName);
    customer.lastName = encryptASCII(customer.lastName);
    customer.username = encryptASCII(customer.username);
    customer.password = hash(customer.password);

    return customer;
}

Customer& Encrypter::encryptCustomerWithoutPassword(Customer& customer) {
    customer.firstName = encryptASCII(customer.firstName);
    customer.lastName = encryptASCII(customer.lastName);
    customer.username = encryptASCII(customer.username);
    return customer;
}

Customer& Encrypter::decryptCustomer(Customer &customer) {
    customer.firstName = decryptASCII(customer.firstName);
    customer.lastName = decryptASCII(customer.lastName);
    customer.username = decryptASCII(customer.username);

    return customer;
}

char Encrypter::encryptChar(char ch) {
    ch = ch + CIPHER_KEY;
    if (ch > 97){
        if (ch > 122) {
            ch = ch - 122;
            ch = ch + 96;
            return ch;
        } else {
            return ch;
        }
    } else if (ch > 65){
        if (ch> 90) {
            ch = ch - 90;
            ch = ch + 64;
            return ch;
        } else {
            return ch;
        }
    } else if (ch > 48) {
        if (ch > 57) {
            ch = ch - 57;
            ch = ch + 47;
            return ch;
        } else {
            return ch;
        }
    }

    return ch;
}

char Encrypter::decryptChar(char ch) {
    ch = ch  - CIPHER_KEY;
    if (ch < 57){
        if (ch < 48) {
            ch = ch - 48;
            ch = ch + 58;
            return ch;
        } else {
            return ch;
        }
    } else if (ch < 90) {
        if (ch < 65) {
            ch = ch - 65;
            ch = ch + 91;
            return ch;
        } else {
            return ch;
        }
    } else if (ch < 122) {
        if (ch < 97) {
            ch = ch - 97;
            ch = ch + 123;
            return ch;
        } else {
            return ch;
        }
    }

    return ch;
}


std::string Encrypter::hash(std::string input) {

    const unsigned int magicNumber = 3415431;
    unsigned int hashed = 12;

    int count = 0;
    while (input[count] != '\0') {
        hashed = hashed ^ (input[count]);
        hashed = hashed * magicNumber;
        count++;
    }

    std::string output;
    std::stringstream hexstream;
    hexstream << std::hex << hashed;
    output = hexstream.str();
    std::transform(output.begin(), output.end(), output.begin(), ::toupper);
    return output;
}


std::string Encrypter::encryptASCII(std::string plainTXT){
    std::string cipherTXT;
    int count = 0;
    while (plainTXT[count] != '\0'){
        cipherTXT += encryptChar(plainTXT[count]);
        count++;
    }
    return cipherTXT;
}


std::string Encrypter::decryptASCII(std::string cipherTXT){
    std::string plainTXT;
    int count = 0;
    while (cipherTXT[count] != '\0'){
        plainTXT += decryptChar(cipherTXT[count]);
        count++;
    }
    return plainTXT;
}


