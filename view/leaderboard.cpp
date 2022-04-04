#include "leaderboard.h"
#include "ui_leaderboard.h"

Leaderboard::Leaderboard(BankingApp* bankApp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Leaderboard)
{
    this->bankApp = bankApp;
    std::cout << bankApp << std::endl;
    ui->setupUi(this);
}

Leaderboard::~Leaderboard()
{
    delete ui;
}

void Leaderboard::on_back_clicked()
{
    emit menuClicked();
}

