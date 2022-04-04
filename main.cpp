#include "view/title.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "bankingapp.h"
#include "controller/transactionhandler.h"
#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"
#include "controller/registerhandler.h"
#include "controller/loginhandler.h"

#include "model/customer.h"
#include "model/transaction.h"


void myTest() {

    // Transaction handler
    TransactionHandler tHandler;
    CredentialsReader cReader;
    std::optional<Customer> customer = cReader.searchByID(1);
    std::optional<Customer> customer2 = cReader.searchByID(2);
    //std::cout << customer << std::endl;

    TransactionStatus status = tHandler.transfer(*customer2, *customer, 100);
    switch(status) {
        case TRANSACTION_SUCCESS:
            std::cout << "TRANSACTION_SUCCESS!" << std::endl;
            break;
        case TRANSACTION_FAILURE:
            std::cout << "TRANSACTION_FAILURE!" << std::endl;
            break;
        case TRANSACTION_LOG_FAILURE:
            std::cout << "TRANSACTION_LOG_FAILURE!" << std::endl;
            break;
    }
    customer->printInfo();
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
