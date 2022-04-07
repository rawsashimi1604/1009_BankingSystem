#ifndef TRANSACTIONREADER_H
#define TRANSACTIONREADER_H

#include "model/transaction.h"
#include "controller/credentialsreader.h"

#include <vector>

class TransactionReader
{

private:
    static const std::string DEFAULT_FILE_LOCATION;
    std::string fileLocation;

public:
    TransactionReader();
    TransactionReader(std::string fileLocation);
    void printHello();
    int getNextID();

    std::optional<Transaction> searchByID(int id);
    std::vector<Transaction> searchAllTransactions(int customerID);
    bool write(Transaction transaction);
    bool update(Transaction transaction);
};

#endif // TRANSACTIONREADER_H
