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

void Leaderboard::getSpendPercentage(){

    double spendPercentile = lHandler.calculatePrcSpend(*bankApp->getCurrentCustomer());

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << spendPercentile;
    std::string spendPrcStr = stream.str();

    std::string message = "You are in the top " + spendPrcStr + "% of all spenders";
    QString s = QString::fromStdString(message);
    ui->spendingsPrc->setText(s);
    ui->spendingsPrc->setWordWrap(true);
}

void Leaderboard::getSavePercentage(){
    double savePercentile = lHandler.calculatePrcSave(*bankApp->getCurrentCustomer());

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << savePercentile;
    std::string savePrcStr = stream.str();

    std::string message = "You are in the top " + savePrcStr + "% of all savers";
    QString s = QString::fromStdString(message);
    ui->savingsPrc->setText(s);
    ui->savingsPrc->setWordWrap(true);
}

void Leaderboard::displayTables(){
    
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
}

