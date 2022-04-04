#include "withdraw.h"
#include "ui_withdraw.h"

Withdraw::Withdraw(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Withdraw)
{
    this->bankApp = bankApp;
    std::cout << bankApp << std::endl;
    ui->setupUi(this);
}

Withdraw::~Withdraw()
{
    delete ui;
}

void Withdraw::on_back_clicked()
{
    emit menuClicked();
}

void Withdraw::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}

