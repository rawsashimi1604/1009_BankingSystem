#include "history.h"
#include "ui_history.h"
#include <iostream>

History::History(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{

    this->bankApp = bankApp;
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_back_clicked()
{
    ui->tableWidget->clear();
    emit menuClicked();
}

void History::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}

void History::tableWidgetDisplay(){
    std::cout << "test" << std::endl;
    std::vector<Transaction> transaction = cReader.searchAllTransactions(bankApp->getCurrentCustomer()->getID());


    QStringList headerLabels;
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(5);
    headerLabels << "transactionID" << "transactionDate" << "customerOut" << "customerIn" << "amountOut" << "amountIn" << "transType";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("first row, first column"));
}

