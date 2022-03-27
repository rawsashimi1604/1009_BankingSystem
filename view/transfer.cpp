#include "transfer.h"
#include "ui_transfer.h"

transfer::transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transfer)
{
    ui->setupUi(this);
}

transfer::~transfer()
{
    delete ui;
}
