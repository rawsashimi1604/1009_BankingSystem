#include "utils.h"

// UtilityFunctions namespace
streamsize UtilityFunctions::setPrintingPrecision() {
    streamsize ss = cout.precision();
    cout << fixed;
    cout << setprecision(2);
    return ss;
}

void UtilityFunctions::removePrintingPrecision(streamsize ss) {
    cout << setprecision(ss);
}

Date UtilityFunctions::getTodaysDate() {
    u_int year = QDate::currentDate().year();
    u_int month = QDate::currentDate().month();
    u_int day = QDate::currentDate().day();

    return Date(year, month, day);
}

// Enums namespace
Enums::TransactionType Enums::convertTransactionType(string& str) {
    if (str == "DEPOSIT") return Enums::TransactionType::DEPOSIT;
    else if (str == "WITHDRAWAL") return Enums::TransactionType::WITHDRAWAL;
    else if (str == "TRANSFER") return Enums::TransactionType::TRANSFER;

    return Enums::TransactionType::NONE;
}

ostream& Enums::operator<<(ostream& COUT, Enums::TransactionType t) {
    int enumVal = static_cast<int>(t);
    string str;
    switch(enumVal) {
        case 0:
            str = "DEPOSIT";
            break;
        case 1:
            str = "WITHDRAWAL";
            break;
        case 2:
            str = "TRANSFER";
            break;
        case 3:
            str = "NONE";
            break;
    }

    COUT << str;
    return COUT;
}

string Enums::convertString(Enums::TransactionType transType) {

    switch(transType) {
        case Enums::TransactionType::DEPOSIT:
            return "DEPOSIT";
        case Enums::TransactionType::WITHDRAWAL:
            return "WITHDRAWAL";
        case Enums::TransactionType::TRANSFER:
            return "TRANSFER";
        case Enums::TransactionType::NONE:
            return "NONE";
    }
    return "NONE";
}


