#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "model.h"
#include "date.h"

class Transaction : public Model
{
private:
    Date transactionDate;

    int customerOut;            // Customer ID whose balance is deducted.
    int customerIn;             // Customer ID whose balance is added, -1 if not applicable

    float amountOut;
    float amountIn;

public:
    Transaction(string dateString);
    void printInfo();
};

#endif // TRANSACTION_H
