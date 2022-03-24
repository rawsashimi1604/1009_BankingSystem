#ifndef TRANSACTIONREADER_H
#define TRANSACTIONREADER_H

#include "reader.h"

class TransactionReader : public Reader
{
public:
    TransactionReader();
    void printHello();
    Model* read(int id);
    void write(Model* model);
};

#endif // TRANSACTIONREADER_H
