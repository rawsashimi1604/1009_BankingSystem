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
    }


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
