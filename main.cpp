#include "view/login.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"
#include "controller/loginhandler.h"

#include "model/customer.h"


void myTest() {

    // Test login
    LoginHandler loginHandler;
    if (loginHandler.login("jasonng", "123456") == AUTHENTICATED) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "FAILURE" << endl;
    }

//    // Test Customer
//    Customer myCustomer("Jason", "Ng", 25, "jason25", "123456", 21, 3, 2022);
//    myCustomer.printInfo();

    // Test Date
//    Date myDate("01/02/2003");
//    myDate.printInfo();

}

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    login m;
    m.show();

    //myTest();

    return a.exec();
    //test
}
