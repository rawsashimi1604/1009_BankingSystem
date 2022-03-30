#include "view/login.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"
#include "controller/loginhandler.h"

#include "model/customer.h"
#include "model/transaction.h"


void myTest() {

//    // Test login
//    LoginHandler loginHandler;
//    if (loginHandler.login("jasonng", "123456") == AUTHENTICATED) {
//        cout << "SUCCESS" << endl;
//    } else {
//        cout << "FAILURE" << endl;
//    }

    // Test TransactionReader
    TransactionReader tReader;

//    // Test Adding transaction to .csv
//    Date date("01/01/2020");
//    Transaction transaction(3, 1, -1, 100, 0, date, Enums::TransactionType::DEPOSIT);

//    tReader.write(transaction);

    vector<Transaction> tArr = tReader.searchAllTransactions(1);

    // Test Transaction printing
    for (Transaction t: tArr) {
        t.printInfo();
    }

    // Test CredentialsReader
    CredentialsReader cReader;

//    // Test adding customer to .csv
//    Customer customer(5, "Admin", "Test", 99, "test", "test", 2022, 3, 30);
//    cReader.write(customer);

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Login m;
    m.show();

    myTest();

    return a.exec();
    //test
}
