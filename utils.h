#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <iomanip>

#include <QDate>

#include "model/date.h"

/**
 * The UtilityFunctions namespace contains a bunch of utility functions to be used around the code base.
 *
 */
namespace UtilityFunctions {

    std::streamsize setPrintingPrecision();                 // Help with printing precision (2 dec place)
    void removePrintingPrecision(std::streamsize ss);       // Help with printing precision (2 dec place)
    int checkNumeric(QString);                              // Check for numeric string for Qstring

    Date getTodaysDate();                                   // Gets today's date according to system time.

}

/**
 * The Enums namespace contains a bunch of utility functions and Enums related to various Enums defined in the code base.
 *
 */
namespace Enums {
    // Transaction
    enum class TransactionType {DEPOSIT, WITHDRAWAL, TRANSFER, NONE};   // Defines possible TransactionTypes

    TransactionType convertTransactionType(std::string& str);           // Converts string -> TransactionType
    std::string convertString(TransactionType transType);               // Converts TransactionType -> string
    std::ostream& operator<<(std::ostream& COUT, TransactionType t);    // Insertion operator overloading for TransactionType
}

#endif // UTILS_H
