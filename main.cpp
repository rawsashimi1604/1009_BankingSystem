#include "view/title.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "bankingapp.h"
#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"
#include "controller/registerhandler.h"
#include "controller/loginhandler.h"

#include "model/customer.h"
#include "model/transaction.h"


void myTest() {

    // Register Handler
    RegisterHandler rHandler;
    RegisterStatus status = rHandler.registerAcc("Gavin", "Loo", 23, "gavin", "gavin123");

    // Transaction Reader
    TransactionReader tReader;
    std::cout << tReader.getNextID() << std::endl;
}


int main(int argc, char *argv[])
{
    BankingApp bankApp;
    BankingApp* bankApp_ptr = &bankApp;

    QApplication a(argc, argv);
    Title mainApp(bankApp_ptr);
    mainApp.show();

    //myTest();

    return a.exec();
    //test
}
