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
    vector<Transaction*> tArr = tReader.searchAllTransactions(1);

    // Test Transaction
    for (Transaction* t: tArr) {
        t->printInfo();
        delete t;
    }

    // Test Adding transaction to .csv
    Date date("01/01/2020");
    Transaction* transaction = new Transaction(1, 1, 2, 100, 0, date, Enums::TransactionType::DEPOSIT);
    tReader.write(transaction);
    delete transaction;

//    // Test CredentialsReader
//    CredentialsReader cReader;

//    // Test adding customer to .csv
//    Customer* customer = new Customer(4, "James", "Collins", 37, "james123", "123456", 2022, 3, 30);
//    for (int i = 0; i < 5; i++) {
//        cReader.write(customer);
//    }

//    delete customer;

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
