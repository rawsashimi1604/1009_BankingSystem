#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfer)
{
    this->bankApp = bankApp;

    std::cout << bankApp << std::endl;

    ui->setupUi(this);
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::on_back_clicked()
{
     emit menuClicked();
}

void Transfer::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}

