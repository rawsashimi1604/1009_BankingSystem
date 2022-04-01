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

