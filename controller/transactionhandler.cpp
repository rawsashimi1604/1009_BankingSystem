#include "transactionhandler.h"

TransactionHandler::TransactionHandler()
{

}

void TransactionHandler::logTransaction(Transaction ) {
    // Use this function as a helper function to help with the other 3 functions
}


TransactionStatus TransactionHandler::withdraw(Customer customer, float amt) {
    // If customer has less than amt, can't withdraw, return TRANSACTION_FAILURE
    // Else, minus amount from Customer, update .csv file with new values
    // If error updating, return TRANSACTION_FAILURE
    // Else, update transactions.csv with new transaction
    // Return TRANSACTION_SUCCESS.

    return TRANSACTION_FAILURE;
}

TransactionStatus TransactionHandler::deposit(Customer customer, float amt) {
    // Add amount to Customer, update .csv file with new values
    // If error updating, return TRANSACTION_FAILURE
    // Else, update transactions.csv with new transaction
    // Return TRANSACTION_SUCCESS.

    return TRANSACTION_FAILURE;
}

TransactionStatus transfer(Customer customerIn, Customer customerOut, float amt) {
    // If customerOut has less than amt, can't transfer, return TRANSACTION_FAILURE
    // Else, minus amount from customerOut, add amount to customerIn, update .csv file with new values
    // If error updating, return TRANSACTION_FAILURE
    // Else, update transactions.csv with new transaction
    // Return TRANSACTION_SUCCESS.

    return TRANSACTION_FAILURE;
}
