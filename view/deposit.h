#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QtWidgets>


#include "bankingapp.h"
#include "controller/transactionhandler.h"
#include "controller/credentialsreader.h"
#include "utils.h"

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;
    Ui::Deposit *ui;
    TransactionHandler transactHandler;
    QMessageBox msgBox;

public:
    explicit Deposit(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Deposit();
    void updateScreenBalance();



private slots:
    void on_back_clicked();

    void on_confirmDeposit_clicked();


signals:
    void menuClicked();




};

#endif // DEPOSIT_H
