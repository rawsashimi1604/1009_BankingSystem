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

    ui->spendingsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->savingsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->spendingsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);     //Disable edit for the table
    ui->savingsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);     //Disable edit for the table
}

Leaderboard::~Leaderboard()
{
    delete ui;
}

void Leaderboard::on_back_clicked()
{
    ui->spendingsTable->clear();
    ui->savingsTable->clear();
    ui->spendingsPrc->clear();
    ui->savingsPrc->clear();
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

void Leaderboard::displayTables(){
    LeaderboardHandler lHandler;
    std::vector<Customer> topSpenders = lHandler.getTopThreeSpenders();
    std::vector<Customer> topSavers = lHandler.getTopThreeSavers();


    //Populate the Spendings table
    for (size_t i=0 ; i< topSpenders.size(); i++){
        for (int j = 0; j < 2; j++){
            if (j==0){
                QString s = QString::fromStdString(topSpenders[i].getUsername());
                ui->spendingsTable->setItem(i,j,new QTableWidgetItem(s));
            }
            if (j==1){
                QString s = QString::number(topSpenders[i].getAmountSpent());
                ui->spendingsTable->setItem(i,j,new QTableWidgetItem(s));
            }
        }
    }

    //Populate the Savings table
    for (size_t i=0 ; i< topSavers.size(); i++){
        for (int j = 0; j < 2; j++){
            if (j==0){
                 QString s = QString::fromStdString(topSavers[i].getUsername());
                ui->savingsTable->setItem(i,j,new QTableWidgetItem(s));
            }
            if (j==1){
                 QString s = QString::number(topSavers[i].getAmountSaved());
                ui->savingsTable->setItem(i,j,new QTableWidgetItem(s));
            }
        }
    }
    ui->spendingsPrc->setText("testing1");
    ui->savingsPrc->setText("testing2");

}
void Leaderboard::getCustomerUsername(){
    std::string username = std::string(bankApp->getCurrentCustomer()->getUsername());

}
