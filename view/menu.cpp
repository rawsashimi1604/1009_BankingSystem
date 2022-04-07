#include "menu.h"
#include "ui_menu.h"

Menu::Menu(BankingApp* bankApp, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Menu),
    withdraw(bankApp),
    deposit(bankApp),
    transfer(bankApp),
    history(bankApp),
    leaderBoard(bankApp)
{
    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));

    //insert all the menu object
    ui->stackedWidget->insertWidget(1,&withdraw);
    ui->stackedWidget->insertWidget(2,&deposit);
    ui->stackedWidget->insertWidget(3,&transfer);
    ui->stackedWidget->insertWidget(4,&history);
    ui->stackedWidget->insertWidget(5,&leaderBoard);

    connect(&withdraw, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
    connect(&deposit, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
    connect(&transfer, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
    connect(&history, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
    connect(&leaderBoard, SIGNAL(menuClicked()),this, SLOT(moveMenu()));
}


Menu::~Menu()
{
    delete ui;
}

void Menu::on_withdraw_clicked()
{
    withdraw.updateScreenBalance();
    ui->stackedWidget->setCurrentIndex(1);
}


void Menu::on_deposit_clicked()
{
    deposit.updateScreenBalance();
    ui->stackedWidget->setCurrentIndex(2);

}

void Menu::on_transfer_clicked()
{
    transfer.updateScreenBalance();
    ui->stackedWidget->setCurrentIndex(3);
}


void Menu::on_transactions_clicked()
{
    history.updateScreenBalance();
    history.tableWidgetDisplay();
    ui->stackedWidget->setCurrentIndex(4);
}

void Menu::on_leaderboard_clicked()
{
    leaderBoard.updateScreenBalance();
    leaderBoard.displayTables();
    ui->stackedWidget->setCurrentIndex(5);
}

void Menu::moveMenu()
{
    ui->stackedWidget->setCurrentIndex(0);

    //When back button click it will update the main menu
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);

}

void Menu::updateScreenBalance(){
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}
