#ifndef CREDENTIALSREADER_H
#define CREDENTIALSREADER_H

#include <QApplication>
#include <QDebug>

#include <iomanip>
#include <string>
#include <fstream>
#include <filesystem>

#include "model/customer.h"

class CredentialsReader
{
private:
    static const std::string DEFAULT_FILE_LOCATION;
    std::string fileLocation;

public:
    CredentialsReader();
    CredentialsReader(std::string fileLocation);
    void printHello();
    int getNextID();
    std::optional<Customer> searchByID(int id);
    std::optional<Customer> searchByUsername(std::string username);
    bool write(Customer customer);
    bool update(Customer customer);
};

#endif // CREDENTIALSREADER_H
