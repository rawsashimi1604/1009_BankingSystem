#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "utils.h"
#include "model/date.h"
#include "model/csvmodel.h"

/**
 * A Customer object contains data information about a Customer.
 * It contains methods and attributes that every Customer should have.
 *
 */
class Customer : public CsvModel
{

    // Friend classes / functions
    friend class Encrypter;
    friend std::ostream& operator<<(std::ostream&, Customer& customerObj);

private:
    static const float INITIAL_STARTING_BALANCE;        // Starting balance when creating bank account


    std::string firstName;                              // Customer first name
    std::string lastName;                               // Customer last name
    int age;                                            // Customer age

    std::string username;                               // Customer username
    std::string password;                               // Customer password

    Date dateRegistered;                                // Customer Date Registered

    float balance;                                      // Customer current balance
    float amountSpent;                                  // Customer total amount spent
    float amountSaved;                                  // Customer total amount saved

public:

    // Constructs customer object using date values
    Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, u_int year, u_int month, u_int day);

    // Constructs customer object using Date object
    Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, Date date);

    // Constructs customer object using date string and customized balanced, amountSpent and amountSaved.
    Customer(int id, std::string firstName, std::string lastName, int age, std::string username, std::string password, std::string dateString, float balance, float amountSpent, float amountSaved);

    ~Customer();                                        // Desconstructs Customer object

    std::vector<std::string> getCsvFormat() const;      // Gets Customer data from database as a vector of strings.

    // Getters   
    std::string getUsername() const;                    // Returns Customer's username
    std::string getPassword() const;                    // Returns Customer's password
    int getAge() const;                                 // Returns Customer's age
    std::string getFirstName() const;                   // Returns Customer's first name
    std::string getLastName() const;                    // Returns Customer's last name
    std::string getFullName() const;                    // Returns Customer's full name
    Date getDateRegistered() const;                     // Returns Customer's date registered
    float getBalance() const;                           // Returns Customer's current balance
    float getAmountSpent() const;                       // Returns Customer's total amount spent
    float getAmountSaved() const;                       // Returns Customer's total amount saved

    // Setters
    void setBalance(float newBalance);                  // Sets Customer's balance
    void setAmountSpent(float newAmountSpent);          // Sets Customer's amount spent
    void setAmountSaved(float newAmountSaved);          // Sets Customer's amount saved
};

std::ostream& operator<<(std::ostream&, Customer& customerObj);     // Overloads insertion operator for Customer object

#endif // CUSTOMER_H
