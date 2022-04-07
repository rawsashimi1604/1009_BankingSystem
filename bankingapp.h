#ifndef BANKINGAPP_H
#define BANKINGAPP_H

#include <iostream>

#include "model/customer.h"

class BankingApp
{

private:
    std::optional<Customer> currCustomer;

public:
    static const std::string APPLICATION_NAME;

    BankingApp();
    void setCurrentCustomer(std::optional<Customer> customer);
    std::optional<Customer> getCurrentCustomer();
};

#endif // BANKINGAPP_H
