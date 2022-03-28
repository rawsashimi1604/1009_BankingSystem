#include "transactionhandler.h"

TransactionHandler::TransactionHandler()
{

}

TransactionStatus TransactionHandler::withdraw(Customer* customer, float amt) {

    return TRANSACTION_FAILURE;
}

TransactionStatus TransactionHandler::deposit(Customer* customer, float amt) {

    return TRANSACTION_FAILURE;
}

TransactionStatus transfer(Customer* fromCustomer, Customer* toCustomer, float amt) {
    return TRANSACTION_FAILURE;
}
