#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "csvmodel.h"
#include "date.h"

#include "controller/credentialsreader.h"
#include "model/customer.h"

class Transaction : public CsvModel
{

private:
    CredentialsReader cReader;

    Date transactionDate;

    int receiverID;             // ID of customer receiving $
    int senderID;               // ID of customer sending $

    float amountReceived;             // Amount of $ received
    float amountSent;            // Amount of $ sent

    Enums::TransactionType transType;

public:
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, Date date, Enums::TransactionType transactionType);
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, u_int year, u_int month, u_int day, Enums::TransactionType transactionType);

    void printInfo() const;
    std::vector<std::string> getCsvFormat() const;

    // Getters
    Enums::TransactionType getTransactionType() const;
    Date getTransactionDate() const;
    int getReceiverID() const;
    int getSenderID() const;
    float getAmountReceived() const;
    float getAmountSent() const;
};

#endif // TRANSACTION_H
