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
    static const string DEFAULT_FILE_LOCATION;
    string fileLocation;

public:
    CredentialsReader();
    CredentialsReader(string fileLocation);
    void printHello();
    int getNextID();
    optional<Customer> searchByID(int id);
    optional<Customer> searchByUsername(string username);
    bool write(Customer customer);
    bool update(Customer customer);
};

#endif // CREDENTIALSREADER_H
