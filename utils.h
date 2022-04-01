#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <iomanip>

#include <QDate>

#include "model/date.h"

using namespace std;

namespace UtilityFunctions {
    // General Util functions

    streamsize setPrintingPrecision();              // Help with printing precision (2 dec place)
    void removePrintingPrecision(streamsize ss);

    Date getTodaysDate();

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
