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

