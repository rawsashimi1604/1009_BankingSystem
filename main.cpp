#include "mainwindow.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"

#include "model/customer.h"


void myTest() {
    // Get current working Directory
    cout << "Current working directory: " << filesystem::current_path() << endl;


    // Test Readers
    CredentialsReader cReader;
    Model* customer = cReader.read(1);
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

    myTest();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    //test
}
