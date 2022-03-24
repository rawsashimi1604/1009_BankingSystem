#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>

#include "date.h"
#include "model.h"

using namespace std;

class Customer : public Model
{

private:

    int id;
    string firstName;
    string lastName;
    int age;

    string username;
    string password;

    Date dateRegistered;

    float balance;
    float amountSpent;
    float amountSaved;

    streamsize setPrintingPrecision();
    void removePrintingPrecision(streamsize ss);

public:

    Customer(int, string, string, int, string, string, u_int, u_int, u_int);
    Customer(int, string, string, int, string, string, string, float, float, float);
    void printInfo();

};

#endif // CUSTOMER_H
