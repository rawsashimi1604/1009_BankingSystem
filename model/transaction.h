#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "model.h"
#include "date.h"

#include "controller/credentialsreader.h"
#include "model/customer.h"

// Possible Transaction Types
enum TransactionType {DEPOSIT, WITHDRAWAL, TRANSFER};

class Transaction : public Model
{

private:
    CredentialsReader cReader;

    int transactionID;
    Date transactionDate;

    const Customer* customerReceived;
    const Customer* customerWithdrawn;

    float amountOut;
    float amountIn;

    TransactionType transType;

    void setTransactionAttributes(int receiverID, int senderID);

public:
    Transaction(int, int, int, float, float, Date);
    Transaction(int, int, int, float, float, u_int, u_int, u_int);
    ~Transaction();
    void printInfo() const;
};

#endif // TRANSACTION_H
