#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "utils.h"
#include "model/date.h"
#include "model/csvmodel.h"
#include "model/model.h"

class Customer : public CsvModel, public Model
{

private:
    static const float INITIAL_STARTING_BALANCE;     // Starting balance when creaing bank account;


    std::string firstName;
    std::string lastName;
    int age;

    std::string username;
    std::string password;

    Date dateRegistered;

    float balance;
    float amountSpent;
    float amountSaved;

public:

    Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, u_int year, u_int month, u_int day);
    Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, Date date);
    Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, std::string dateString, float balance, float amountSpent, float amountSaved);
    ~Customer();

    void printInfo() const;
    std::vector<std::string> getCsvFormat() const;

    // Getters   
    std::string getUsername() const;
    std::string getPassword() const;
    int getAge() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
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
