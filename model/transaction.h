#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "csvmodel.h"
#include "date.h"

#include "customer.h"

/**
 * A Transaction object contains data information about a Transaction.
 * It contains methods and attributes that every Transaction should have.
 * And generalizes how we represent transactions in the code base.
 */
class Transaction : public CsvModel
{

    // Friend classes / functions
    friend std::ostream& operator<<(std::ostream&, Transaction transactionObj);

private:

    Date transactionDate;               // Date of transaction

    int receiverID;                     // ID of customer receiving $
    int senderID;                       // ID of customer sending $

    float amountReceived;               // Amount of $ received
    float amountSent;                   // Amount of $ sent

    Enums::TransactionType transType;   // Type of transaction DEPOSIT, WITHDRAWAL, TRANSFER, NONE

public:
    // Construct Transaction Object with Date object
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, Date date, Enums::TransactionType transactionType);

    // Construct Transaction Object with integer values
    Transaction(int id, int receiverID, int senderID, float amountReceived, float amountSent, u_int year, u_int month, u_int day, Enums::TransactionType transactionType);

    std::vector<std::string> getCsvFormat() const;          // Gets Transaction data from database as a vector of strings.

    // Getters
    Enums::TransactionType getTransactionType() const;      // Gets Transaction Type
    Date getTransactionDate() const;                        // Gets Transaction Date
    int getReceiverID() const;                              // Gets Receiver ID
    int getSenderID() const;                                // Gets Sender ID
    float getAmountReceived() const;                        // Gets Amount received
    float getAmountSent() const;                            // Gets Amount sent
};

std::ostream& operator<<(std::ostream&, Transaction transactionObj);    // Overloads insertion operator for Transaction object

#endif // TRANSACTION_H
