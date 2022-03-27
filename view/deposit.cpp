#include "deposit.h"
#include "ui_deposit.h"

deposit::deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deposit)
{
    ui->setupUi(this);
}

deposit::~deposit()
{
    delete ui;
}
