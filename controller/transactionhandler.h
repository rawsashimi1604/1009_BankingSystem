#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "model/customer.h"
#include "model/transaction.h"

#define TRANSACTION_SUCCESS 1
#define TRANSACTION_FAILURE 0

typedef int TransactionStatus;

class TransactionHandler
{
private:
    void logTransaction(Transaction);

public:
    TransactionHandler();
    TransactionStatus withdraw(Customer customer, float amt);
    TransactionStatus deposit(Customer customer, float amt);
    TransactionStatus transfer(Customer fromCustomer, Customer toCustomer, float amt);
};

#endif // TRANSACTIONHANDLER_H
