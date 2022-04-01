#include "view/title.h"

#include <QApplication>

#include <vector>
#include <filesystem>

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
