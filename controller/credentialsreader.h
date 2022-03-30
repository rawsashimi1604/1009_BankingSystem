#ifndef CREDENTIALSREADER_H
#define CREDENTIALSREADER_H

#include <QApplication>
#include <QDebug>

#include <iomanip>
#include <string>
#include <fstream>

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
    optional<Customer> searchByID(int id);
    optional<Customer> searchByUsername(string username);
    bool write(Customer customer);
};

#endif // CREDENTIALSREADER_H
