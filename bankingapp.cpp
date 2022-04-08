#include "bankingapp.h"

const std::string BankingApp::APPLICATION_NAME = "Banking Simulation Application";

/**
 * Constructs BankingApp Object
 *
 * @param None
 */
BankingApp::BankingApp()
{

}


/**
 * Set currCustomer to specified Customer
 *
 * @param customer -> pointer to current customer object
 * @return None
 */
void BankingApp::setCurrentCustomer(std::optional<Customer> customer) {
    this->currCustomer = customer;
}

/**
 * Get currCustomer logged in
 *
 * @param None
 * @return Currently logged in Customer.
 */
std::optional<Customer> BankingApp::getCurrentCustomer() {
    return this->currCustomer;
}
