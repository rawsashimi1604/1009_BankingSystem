#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "model/customer.h"
#include "model/transaction.h"
#include "controller/transactionreader.h"
#include "controller/credentialsreader.h"

/**
 * TransactionHandler contains a set of functions that interface with the Desposit, Withdrawal, Transfer View page.
 */

#define TRANSACTION_SUCCESS 1                                                       // Transaction SUCCESS, added to transactions database.
#define TRANSACTION_FAILURE 0                                                       // Transcation FAILURE, invalid transaction.
#define TRANSACTION_LOG_FAILURE -1                                                  // Transaction FAILURE, unable to log into database.

typedef int TransactionStatus;                                                      // Defines TransactionStatus type (int)

class TransactionHandler
{
private:
    bool logTransaction(int recieverId, int senderId, float amount_recieved, float amount_sent, Enums::TransactionType type); // Logs transaction in transaction database.
public:
    TransactionHandler();                                                               // Constructs the LeaderboardHandler object.
    TransactionStatus withdraw(Customer customer, float amt);                           // Withdraws specfied amount from Customer account.
    TransactionStatus deposit(Customer customer, float amt);                            // Deposits specified amount to Customer account.
    TransactionStatus transfer(Customer fromCustomer, Customer toCustomer, float amt);  // Transfer specified amount between 2 Customer accounts.
};

#endif // TRANSACTIONHANDLER_H
