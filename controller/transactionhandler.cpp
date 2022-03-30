#include "transactionhandler.h"

TransactionHandler::TransactionHandler()
{

}

void TransactionHandler::logTransaction(Transaction) {

}


TransactionStatus TransactionHandler::withdraw(Customer customer, float amt) {

    return TRANSACTION_FAILURE;
}

TransactionStatus TransactionHandler::deposit(Customer customer, float amt) {

    return TRANSACTION_FAILURE;
}

TransactionStatus transfer(Customer customerIn, Customer customerOut, float amt) {
    return TRANSACTION_FAILURE;
}
