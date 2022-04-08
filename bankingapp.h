#ifndef BANKINGAPP_H
#define BANKINGAPP_H

#include <iostream>

#include "model/customer.h"

/**
 * The BankingApp class contains data that is shared among all view pages
 * It is commonly accessed by reference and each view class is made up of a reference to this shared data object.
 *
 */
class BankingApp
{

private:
    std::optional<Customer> currCustomer;                           // Current Customer logged in

public:
    static const std::string APPLICATION_NAME;                      // Application Name

    BankingApp();                                                   // Constructs BankingApp Object
    void setCurrentCustomer(std::optional<Customer> customer);      // Set currCustomer to specified Customer
    std::optional<Customer> getCurrentCustomer();                   // Get currCustomer logged in
};

#endif // BANKINGAPP_H
