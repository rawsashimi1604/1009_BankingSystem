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
#include "controller/encrypter.h"

#include "model/customer.h"
#include "model/transaction.h"


void myTest() {

    std::string password = "password123";
    Encrypter e;

    std::string hashed = e.hash(password);

    std::cout << "password: " << password << std::endl;
    std::cout << "hashed: " << hashed << std::endl;

    std::string username = "100.00";
    std::string encrypted = e.encryptASCII(username);

    std::cout << "encrypted username: " << encrypted << std::endl;

}


int main(int argc, char *argv[])
{
    BankingApp bankApp;
    BankingApp* bankApp_ptr = &bankApp;

    QApplication a(argc, argv);
    Title mainApp(bankApp_ptr);
    mainApp.show();

    myTest();

    return a.exec();
    //test
}
