#ifndef TRANSACTIONREADER_H
#define TRANSACTIONREADER_H

#include "model/transaction.h"
#include "controller/credentialsreader.h"

#include <vector>

/**
 * TransactionReader allows access to the transactions.csv database.
 *
 * It allows reading, writing, and updating.
 *
 */
class TransactionReader
{

private:
    static const std::string DEFAULT_FILE_LOCATION;                         // The default file location of transactions.csv
    std::string fileLocation;                                               // File location of transactions.csv (customizable)

public:
    TransactionReader();                                                    // Constructs TransactionReader with the DEFAULT_FILE_LOCATION
    TransactionReader(std::string fileLocation);                            // Constructs TransactionReader with specified file location.
    void printHello();                                                      // Testing function
    int getNextID();                                                        // Gets the next ID available for use in the database.

    std::optional<Transaction> searchByID(int id);                          // Returns Transaction object pointer with the given ID, NULL if not found.
    std::vector<Transaction> searchAllTransactions(int customerID);         // Returns a vector of all Transactions in the database with the specified customer ID.
    bool write(Transaction transaction);                                    // Appends a Transaction to the database.
    bool update(Transaction transaction);                                   // Updates a Transaction in the database. (Uses ID to identify transaction)
};

#endif // TRANSACTIONREADER_H
