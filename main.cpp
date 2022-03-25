#include "mainwindow.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"

#include "model/customer.h"


void myTest() {
    // Test Readers
    CredentialsReader cReader;
    Model* customer = cReader.read(2);
    customer->printInfo();





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
    MainWindow w;
    w.show();

    myTest();

    return a.exec();
}
