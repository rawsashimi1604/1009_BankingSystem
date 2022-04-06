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

    l.login("test", "test");

//    std::string s = "obama123";

//    std::cout << "String is: " << s << std::endl;

//    s = e.encryptASCII(s);
//    std::cout << "Encrypted is: " << s << std::endl;
//    s = e.decryptASCII(s);
//    std::cout << "Decrypted is: " << s << std::endl;

//    int id = cReader.getNextID();
//    std::string fName = "test";
//    std::string lName = "test";
//    int age = 60;
//    std::string username = "test";
//    std::string password = "test";

//    Customer c(id, fName, lName, age, username, password, UtilityFunctions::getTodaysDate());   // write encrypted customer
//    cReader.write(c);
//    Customer getC = *(cReader.searchByID(id));
//    getC.printInfo();
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
