#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <iomanip>

#include <QDate>

#include "model/date.h"

// General Util functions
namespace UtilityFunctions {

    std::streamsize setPrintingPrecision();              // Help with printing precision (2 dec place)
    void removePrintingPrecision(std::streamsize ss);
    int checkNumeric(QString); // Check for numeric string for Qstring

    Date getTodaysDate();

}

// List of enums and their functions
namespace Enums {
    // Transaction
    enum class TransactionType {DEPOSIT, WITHDRAWAL, TRANSFER, NONE};

    TransactionType convertTransactionType(std::string& str);
    std::string convertString(TransactionType transType);
    std::ostream& operator<<(std::ostream& COUT, TransactionType t);
}

#endif // UTILS_H
