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

// Enums namespace
Enums::TransactionType Enums::convertTransactionType(string& str) {
    if (str == "DEPOSIT") return Enums::TransactionType::DEPOSIT;
    else if (str == "WITHDRAWAL") return Enums::TransactionType::WITHDRAWAL;
    else if (str == "TRANSFER") return Enums::TransactionType::TRANSFER;

    return Enums::TransactionType::NONE;
}

ostream& operator<<(ostream& COUT, Enums::TransactionType t) {
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


