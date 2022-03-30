#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{
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

