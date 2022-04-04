#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QtWidgets>

#include "bankingapp.h"
#include "controller/transactionhandler.h"
#include "utils.h"

namespace Ui {
class Withdraw;
}

class Withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Withdraw();
    void updateScreenBalance();

private:
    Ui::Withdraw *ui;
    BankingApp* bankApp;
    TransactionHandler transactHandler;
    QMessageBox msgBox;

private slots:
    void on_back_clicked();

    void on_cfmWithdraw_clicked();

signals:
    void menuClicked();

};

#endif // WITHDRAW_H
