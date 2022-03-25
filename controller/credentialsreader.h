#ifndef CREDENTIALSREADER_H
#define CREDENTIALSREADER_H

#include <QApplication>
#include <QDebug>

#include <iomanip>
#include <string>
#include <fstream>

#include "reader.h"
#include "model/customer.h"


class CredentialsReader : public Reader
{
private:
    static const string DEFAULT_FILE_LOCATION;
    string fileLocation;

public:
    CredentialsReader();
    CredentialsReader(string fileLocation);
    void printHello();
    Model* read(int id);
    void write(Model* customer);
};

#endif // CREDENTIALSREADER_H
