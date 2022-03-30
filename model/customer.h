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
    static const float INITIAL_STARTING_BALANCE;     // Starting balance when creaing bank account;


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

    Customer(int id, string firstName, string lastName, int age, string username, string password, u_int year, u_int month, u_int day);
    Customer(int id, string firstName, string lastName, int age, string username, string password, string dateString, float balance, float amountSpent, float amountSaved);
    ~Customer();
    void printInfo() const;

    // Getters
    int getID() const;
    string getUsername() const;
    string getPassword() const;
    int getAge() const;
    string getFirstName() const;
    string getLastName() const;
    string getFullName() const;
    Date getDateRegistered() const;
    float getBalance() const;
    float getAmountSpent() const;
    float getAmountSaved() const;
};

#endif // CUSTOMER_H
