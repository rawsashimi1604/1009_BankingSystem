#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "model/customer.h"

/**
 * Encrypter has encryption and decryption features.
 *
 * It uses Caesar Cipher to encrypt Customer's username, first name, and last name.
 * For password, it is encrypted using hashing.
 */

#define CIPHER_KEY 3                                                    // Cipher Key for Caesar Cipher

class Encrypter
{

private:
    char encryptChar(char ch);                                          // Encrypts character using Caesar Cipher
    char decryptChar(char ch);                                          // Decrypts character using Caesar Cipher

public:
    Encrypter();                                                        // Constructs Encrypter object

    Customer& encryptCustomer(Customer& customer);                      // Encrypts customer's username, first name, last name and password
    Customer& encryptCustomerWithoutPassword(Customer& customer);       // Encrypts customer's username, first name, last name
    Customer& decryptCustomer(Customer& customer);                      // Decrypts customer's username, first name, last name
    std::string hash(std::string input);                                // Hashes input string, used for password
    std::string encryptASCII(std::string);                              // Encrypts input string using Caesar Cipher
    std::string decryptASCII(std::string);                              // Decrypts input string using Caesar Cipher
};

#endif // ENCRYPTER_H
