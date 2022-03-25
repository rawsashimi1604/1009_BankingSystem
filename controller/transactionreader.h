#ifndef TRANSACTIONREADER_H
#define TRANSACTIONREADER_H

#include "model/transaction.h"

class TransactionReader
{
public:
    TransactionReader();
    void printHello();
    Transaction* read(int id);
    void write(Transaction* model);
};

#endif // TRANSACTIONREADER_H
