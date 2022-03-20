#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>

#include "date.h"

using namespace std;

class Customer
{

private:

    string firstName;
    string lastName;
    int age;

    string username;
    string password;

    Date dateRegistered;

    float balance;

    streamsize setPrintingPrecision();
    void removePrintingPrecision(streamsize ss);

public:
    Customer(string, string, int, string, string, u_int, u_int, u_int);
    void printInfo();

};

#endif // CUSTOMER_H
