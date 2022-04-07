#include "bankingapp.h"

const std::string BankingApp::APPLICATION_NAME = "Banking Simulation Application";

BankingApp::BankingApp()
{

}

void BankingApp::setCurrentCustomer(std::optional<Customer> customer) {
    this->currCustomer = customer;
}

std::optional<Customer> BankingApp::getCurrentCustomer() {
    return this->currCustomer;
}
