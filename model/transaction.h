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

    int receiverID;             // ID of customer receiving $
    int senderID;               // ID of customer sending $

    float amountReceived;             // Amount of $ received
    float amountSent;            // Amount of $ sent

    TransactionType transType;

public:
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, Date date, TransactionType transactionType);
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, u_int year, u_int month, u_int day, TransactionType transactionType);
    void printInfo() const;

    // Getters
    TransactionType getTransactionType();
};

#endif // TRANSACTION_H
