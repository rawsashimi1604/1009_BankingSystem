#ifndef MENU_H
#define MENU_H

#include <QWidget>

#include "bankingapp.h"
#include "view/withdraw.h"
#include "view/deposit.h"
#include "view/transfer.h"
#include "view/history.h"
#include "view/leaderboard.h"



namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_withdraw_clicked();

    void on_deposit_clicked();

    void on_transfer_clicked();

    void on_transactions_clicked();

    void moveMenu();

    void on_leaderboard_clicked();

private:
    Ui::Menu *ui;

    BankingApp* bankApp;

    //initialise all the menu ui classes
    Withdraw withdraw;
    Deposit deposit;
    Transfer transfer;
    History history;
    Leaderboard leaderBoard;

 signals:
    void buttonClicked();


};

#endif // MENU_H
