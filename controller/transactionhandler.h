#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "model/customer.h"
#include "model/transaction.h"
#include "controller/transactionreader.h"


#define TRANSACTION_SUCCESS 1
#define TRANSACTION_FAILURE 0
#define TRANSACTION_LOG_FAILURE -1

typedef int TransactionStatus;

class TransactionHandler
{
private:
    bool logTransaction(int recieverId, int senderId, float amount_recieved, float amount_sent, Enums::TransactionType type);
public:
    TransactionHandler();
    TransactionStatus withdraw(Customer customer, float amt);
    TransactionStatus deposit(Customer customer, float amt);
    TransactionStatus transfer(Customer fromCustomer, Customer toCustomer, float amt);
};

#endif // TRANSACTIONHANDLER_H
