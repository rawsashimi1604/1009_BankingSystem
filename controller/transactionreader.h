#ifndef TRANSACTIONREADER_H
#define TRANSACTIONREADER_H

#include "model/transaction.h"

#include <vector>

class TransactionReader
{

private:
    static const string DEFAULT_FILE_LOCATION;
    string fileLocation;

public:
    TransactionReader();
    TransactionReader(string fileLocation);
    void printHello();

    optional<Transaction> searchByID(int id);
    vector<Transaction> searchAllTransactions(int customerID);
    bool write(Transaction transaction);
    bool update(Transaction transaction);
};

#endif // TRANSACTIONREADER_H
