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


    Encrypter e;
    CredentialsReader cReader;
    LoginHandler l;

//    // Test Add User
//    int id = cReader.getNextID();
//    std::string fName = "Barack";
//    std::string lName = "Obama";
//    int age = 70;
//    std::string username = "barack";
//    std::string password = "obama123";

//    Customer c(id, fName, lName, age, username, password, UtilityFunctions::getTodaysDate());   // write encrypted customer
//    cReader.write(c);
//    Customer getC = *(cReader.searchByID(id));
//    getC.printInfo();

    std::vector<Customer> customers = cReader.getAllCustomers();

    for (Customer& c : customers) {
        std::cout << c.getFullName() << std::endl;
    }

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
