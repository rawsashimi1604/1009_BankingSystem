#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>

#include "utils.h"
#include "model/date.h"
#include "model/model.h"

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

public:

    Customer(int, string, string, int, string, string, u_int, u_int, u_int);
    Customer(int, string, string, int, string, string, string, float, float, float);
    ~Customer();
    void printInfo() const;

    // Getters
    int getID() const;
    string getUsername() const;
    string getPassword() const;
    int getAge() const;
    string getFullName() const;
    float getBalance() const;
    float getAmountSpent() const;
    float getAmountSaved() const;
};

#endif // CUSTOMER_H
