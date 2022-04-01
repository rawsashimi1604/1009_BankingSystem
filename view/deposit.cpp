#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{

    this->bankApp = bankApp;
    std::cout << bankApp << std::endl;
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::on_back_clicked()
{
    emit menuClicked();
}

