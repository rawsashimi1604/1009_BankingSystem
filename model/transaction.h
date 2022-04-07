#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "csvmodel.h"
#include "date.h"

#include "customer.h"

class Transaction : public CsvModel
{

    // Friend classes / functions
    friend std::ostream& operator<<(std::ostream&, Transaction transactionObj);

private:

    Date transactionDate;

    int receiverID;             // ID of customer receiving $
    int senderID;               // ID of customer sending $

    float amountReceived;       // Amount of $ received
    float amountSent;           // Amount of $ sent

    Enums::TransactionType transType;

public:
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, Date date, Enums::TransactionType transactionType);
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, u_int year, u_int month, u_int day, Enums::TransactionType transactionType);

    std::vector<std::string> getCsvFormat() const;

    // Getters
    Enums::TransactionType getTransactionType() const;
    Date getTransactionDate() const;
    int getReceiverID() const;
    int getSenderID() const;
    float getAmountReceived() const;
    float getAmountSent() const;
};

std::ostream& operator<<(std::ostream&, Transaction transactionObj);

#endif // TRANSACTION_H
