#include "leaderboard.h"
#include "ui_leaderboard.h"

Leaderboard::Leaderboard(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Leaderboard)
{
    this->bankApp = bankApp;
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(bankApp->APPLICATION_NAME));
    QCoreApplication::setApplicationName(QString::fromStdString(bankApp->APPLICATION_NAME));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Leaderboard::~Leaderboard()
{
    delete ui;
}

void Leaderboard::on_back_clicked()
{
    emit menuClicked();
}

void Leaderboard::updateScreenBalance(){
    //When deposit button is clicked, it will update its balance
    QString balance = QString::number(bankApp->getCurrentCustomer()->getBalance());
    ui->balance->display(balance);
}
