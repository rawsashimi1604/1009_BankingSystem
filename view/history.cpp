#include "history.h"
#include "ui_history.h"

History::History(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{

    this->bankApp = bankApp;
    std::cout << bankApp << std::endl;
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_back_clicked()
{
    emit menuClicked();
}

void History::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}

