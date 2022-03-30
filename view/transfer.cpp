#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfer)
{
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

