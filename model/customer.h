#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "utils.h"
#include "model/date.h"
#include "model/csvmodel.h"

using namespace std;

class Customer : public CsvModel
{

private:
    static const float INITIAL_STARTING_BALANCE;     // Starting balance when creaing bank account;


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
    Customer(int id, string firstName, string lastName, int age, string username, string password, Date date);
    Customer(int id, string firstName, string lastName, int age, string username, string password, string dateString, float balance, float amountSpent, float amountSaved);
    ~Customer();

    void printInfo() const;
    vector<string> getCsvFormat() const;

    // Getters   
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

    // Setters
    void setBalance(float newBalance);
    void setAmountSpent(float newAmountSpent);
    void setAmountSaved(float newAmountSaved);
};

#endif // CUSTOMER_H
