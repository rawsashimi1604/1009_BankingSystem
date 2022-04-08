#ifndef CREDENTIALSREADER_H
#define CREDENTIALSREADER_H

#include <QApplication>
#include <QDebug>

#include <iomanip>
#include <string>
#include <fstream>
#include <filesystem>

#include "model/customer.h"
#include "controller/encrypter.h"

/**
 * CredentialsReader allows access to the customers.csv database.
 *
 * It allows reading, writing, and updating. The customers database is encrypted using Encrypter. (Caesar Cipher and Hashing)
 *
 */
class CredentialsReader
{
private:
    Encrypter e;                                                        // Used to for encryption and decryption of database
    static const std::string DEFAULT_FILE_LOCATION;                     // The default file location of customers.csv
    std::string fileLocation;                                           // File location of customers.csv (customizable)

public:


    CredentialsReader();                                                // Constructs CredentialsReader with the DEFAULT_FILE_LOCATION
    CredentialsReader(std::string fileLocation);                        // Constructs CredentialsReader with specified file location.
    void printHello();                                                  // Testing function
    int getNextID();                                                    // Gets the next ID available for use in the database.
    std::optional<Customer> searchByID(int id);                         // Returns Customer object pointer with the given ID, NULL if not found.
    std::optional<Customer> searchByUsername(std::string username);     // Returns Customer object pointer with the given username, NULL if not found.
    std::vector<Customer> getAllCustomers();                            // Returns a vector of all Customers in the database.
    bool write(Customer customer);                                      // Appends a Customer to the database.
    bool update(Customer customer);                                     // Updates a Customer in the database. (Uses ID to identify customer)
};

#endif // CREDENTIALSREADER_H
