#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    //insert all the menu object
    ui->stackedWidget->insertWidget(1,&withdraw);
    ui->stackedWidget->insertWidget(2,&deposit);
    ui->stackedWidget->insertWidget(3,&transfer);
    ui->stackedWidget->insertWidget(4,&history);

    connect(&withdraw, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
    connect(&deposit, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
    connect(&transfer, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
    connect(&history, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_withdraw_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Menu::on_deposit_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Menu::on_transfer_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Menu::on_transactions_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Menu::moveMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}

