#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "model.h"
#include "date.h"

#include "controller/credentialsreader.h"
#include "model/customer.h"

// Possible Transaction Types
enum class TransactionType {DEPOSIT, WITHDRAWAL, TRANSFER, NONE};

TransactionType convertTransactionType(string& str);
ostream& operator<<(ostream& COUT, TransactionType t);


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
    Transaction(int id, int receiverID, int senderID, float incoming, float outgoing, Date date, TransactionType transactionType);
    Transaction(int id, int receiverID, int senderID, float incoming, float outgoing, u_int year, u_int month, u_int day, TransactionType transactionType);
    ~Transaction();
    void printInfo() const;

    // Getters
    TransactionType getTransactionType();
};

#endif // TRANSACTION_H
