#include "view/title.h"

#include <QApplication>

#include <vector>
#include <filesystem>

#include "bankingapp.h"
#include "controller/transactionhandler.h"
#include "controller/credentialsreader.h"
#include "controller/leaderboardhandler.h"
#include "controller/transactionreader.h"
#include "controller/registerhandler.h"
#include "controller/loginhandler.h"
#include "controller/encrypter.h"

#include "model/customer.h"
#include "model/transaction.h"


void myTest() {


    Encrypter e;
    CredentialsReader cReader;
    TransactionReader tReader;
    LeaderboardHandler lHandler;
    LoginHandler l;

    lHandler.getTopThreeSpenders();
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
