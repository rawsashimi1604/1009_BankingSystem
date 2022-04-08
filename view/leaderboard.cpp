#include "leaderboard.h"
#include "ui_leaderboard.h"
#include "controller/leaderboardhandler.h"

Leaderboard::Leaderboard(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Leaderboard)
{
    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Leaderboard::~Leaderboard()
{
    delete ui;
}

void Leaderboard::on_back_clicked()
{
    emit menuClicked();
}

void Leaderboard::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}
void Leaderboard::getCustomerAmountsave(){
    QString AmtSave = QString::number(bankApp->getCurrentCustomer()->getBalance()); //currently getAmountSave() gives 0
    ui->amtSave->display(AmtSave);
}
void Leaderboard::getCustomerAmountspend(){
    QString AmtSpend = QString::number(bankApp->getCurrentCustomer()->getAmountSpent());
    ui->amtSpend->display(AmtSpend);
}
void Leaderboard::getSavePercentage(){
    QString saving = QString::number(bankApp->getCurrentCustomer()->getBalance());
    QString spending = QString::number(bankApp->getCurrentCustomer()->getAmountSpent());

    bool ok1,ok2;
    int save = saving.toInt(&ok1);
    int spend = spending.toInt(&ok2);

    if (!ok1) {
      // conversion failed
        std::cout << "save conversion fail"<<std::endl;
    }
    if (!ok2) {
      // conversion failed
        std::cout << "spend conversion fail"<<std::endl;
    }
    int percent = 100* save/(save + spend);
    QString percentSave = QString::number(percent);

    ui->savepercent->display(percentSave);
}
void Leaderboard::getSpendPercentage(){
    QString saving = QString::number(bankApp->getCurrentCustomer()->getBalance());
    QString spending = QString::number(bankApp->getCurrentCustomer()->getAmountSpent());

    bool ok1,ok2;
    int save = saving.toInt(&ok1);
    int spend = spending.toInt(&ok2);

    if (!ok1) {
      // conversion failed
        std::cout << "save conversion fail"<<std::endl;
    }
    if (!ok2) {
      // conversion failed
        std::cout << "spend conversion fail"<<std::endl;
    }
    int percent = 100* spend/(save + spend);
    QString percentSpend = QString::number(percent);

    ui->spendpercent->display(percentSpend);
}

//void Leaderboard::tableWidgetDisplay(){
//    std::cout << "test" << std::endl;
//    std::vector<Customer> top3spender = cReader.getTopThreeSpenders();
//    int rowCount = 0;

////    for (Transaction tract: transaction){
////        tract.printInfo();
////    }

//    for (size_t i=0; i< top3spender.size(); i++){
//        //std::cout << transaction[79].getAmountReceived()  << std::endl;
//        rowCount++;
//    }


//    QStringList headerLabels;
//    ui->tableWidget->setColumnCount(3);
//    ui->tableWidget->setRowCount(rowCount);
//    headerLabels  << "Ranking" << "Username" << "Spending";
//    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

//    int reverseList = rowCount-1;
//    for (size_t i=0; i< top3spender.size(); i++){
//        std::cout<< reverseList << std::endl;
//        for (int j = 0; j < 3; j++){
//            if (j == 0){

//                //QString s = QString::fromStdString(tDate.getDateString());
//                QString user = top3spender.getTopThreeSpenders();
//                ui->tableWidget->setItem(i,j,new QTableWidgetItem(user));
//            }
//            if (j ==1){
//                int id1 = transaction[reverseList].getSenderID();
//                if (id1 != -1){
//                    std::optional<Customer> cust =  cReader.searchByID(id1);
//                    QString s = QString::fromStdString(cust->getUsername());
//                    ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
//                }
//            }
//            if (j == 2){
//               int id2 = transaction[reverseList].getReceiverID();
//               if (id2 != -1){
//                   std::optional<Customer> cust =  cReader.searchByID(id2);
//                   QString s = QString::fromStdString(cust->getUsername());
//                   ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
//               }
//            }
//            if (j == 3){
//                QString s = QString::number(transaction[reverseList].getAmountSent());
//                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
//            }
//            if (j == 4){
//                QString s = QString::number(transaction[reverseList].getAmountReceived());
//                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
//            }
//            if (j == 5){
//                std::string tType = Enums::convertString(transaction[reverseList].getTransactionType());
//                QString s = QString::fromStdString(tType);
//                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
//            }
//        }
//        reverseList--;
//    }


//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);     //Disable edit for the table
//}
