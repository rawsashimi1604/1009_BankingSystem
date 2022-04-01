#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <iostream>
#include <QWidget>

#include "bankingapp.h"

namespace Ui {
class Withdraw;
}

class Withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Withdraw();

private slots:
    void on_back_clicked();

private:
    Ui::Withdraw *ui;
    BankingApp* bankApp;

signals:
    void menuClicked();

};

#endif // WITHDRAW_H
