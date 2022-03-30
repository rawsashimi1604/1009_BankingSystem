#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

namespace UtilityFunctions {
    // General Util functions
    streamsize setPrintingPrecision();
    void removePrintingPrecision(streamsize ss);
}

// List of enums and their functions
namespace Enums {
    // Transaction
    enum class TransactionType {DEPOSIT, WITHDRAWAL, TRANSFER, NONE};

    TransactionType convertTransactionType(string& str);
    string convertString(TransactionType transType);
    ostream& operator<<(ostream& COUT, TransactionType t);
}

#endif // UTILS_H
