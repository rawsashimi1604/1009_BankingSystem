#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

#include "bankingapp.h"

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Deposit();
    void updateScreenBalance();

private:
    BankingApp* bankApp;
    Ui::Deposit *ui;

signals:
    void menuClicked();



private slots:
    void on_back_clicked();

};

#endif // DEPOSIT_H
