#include "mainwindow.h"

#include <QApplication>

#include <vector>

#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"

#include "model/customer.h"

void myTest() {
    // Test Readers
    vector<Reader*> myReaderArray;

    CredentialsReader* CReader = new CredentialsReader();
    myReaderArray.push_back(CReader);

    TransactionReader* TReader = new TransactionReader();
    myReaderArray.push_back(TReader);

    for (Reader* r : myReaderArray) {
        r->printHello();
    }

    // Test Customer
    Customer myCustomer("Jason", "Ng", 25, "jason25", "123456", 21, 3, 2022);
    myCustomer.printInfo();
}

int main(int argc, char *argv[])
{

    myTest();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
