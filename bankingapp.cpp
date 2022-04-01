#include "bankingapp.h"

BankingApp::BankingApp()
{

}

void BankingApp::setCurrentCustomer(std::optional<Customer> customer) {
    this->currCustomer = customer;
}

std::optional<Customer> BankingApp::getCurrentCustomer() {
    return this->currCustomer;
}
