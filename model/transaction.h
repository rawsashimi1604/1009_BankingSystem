#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "model.h"
#include "date.h"

class Transaction : public Model
{
public:
    Transaction();
    void printInfo();
};

#endif // TRANSACTION_H
