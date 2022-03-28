#include "transaction.h"

Transaction::Transaction(int reciever, int sender, float incoming, float outgoing, u_int year, u_int month, u_int day)
    : transactionDate(year, month, day),
      customerOut(0),
      customerIn(0),
      amountOut(0),
      amountIn(0)

{
    this->customerOut = sender;
    this->customerIn = reciever;
    this->amountIn = incoming;
    this->amountOut = outgoing;
}

void Transaction::printInfo() {

    cout << "====================================TRANSACTION HISTORY====================================" << endl;
    cout << "||   Type  ||    Date    ||    From    ||    To    ||    Amount In    ||    Amount Out   ||" << endl;
    if (transType == DEPOSIT){
        customerIn = customerOut;
        cout << "DEPOSIT, "; transactionDate.printInfo(); cout << "," << customerOut << "," << customerIn << "," << amountIn << "," << amountOut << endl;
    }
    if (transType == WITHDRAWAL){
        customerIn = customerOut;
        cout << "WITHDRAW, "; transactionDate.printInfo(); cout << "," << customerOut << "," << customerIn << "," << amountIn << "," << amountOut << endl;
    }
    if (transType == TRANSFER){
        cout << "TRANSFER, "; transactionDate.printInfo(); cout << "," << customerOut << "," << customerIn << "," << amountIn << "," << amountOut << endl;
        cout << "TRANSFER, "; transactionDate.printInfo(); cout << "," << customerIn << "," << customerOut << "," << amountOut << "," << amountIn << endl;
    }
}
