#include "leaderboard.h"
#include "ui_leaderboard.h"

Leaderboard::Leaderboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Leaderboard)
{
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

