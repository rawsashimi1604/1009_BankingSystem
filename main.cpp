#include "view/title.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "controller/credentialsreader.h"
#include "controller/transactionreader.h"
#include "controller/loginhandler.h"

#include "model/customer.h"
#include "model/transaction.h"


void myTest() {

    // Test Transaction Reader Update
    TransactionReader tReader;
    Date date("04/05/2007");
    Transaction t(4, 1, -1, 100, 0, date, Enums::TransactionType::DEPOSIT);\
    tReader.update(t);

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Title main;
    main.show();

    myTest();

    return a.exec();
    //test
}
