#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QWidget>

#include "bankingapp.h"
#include "controller/leaderboardhandler.h"

namespace Ui {
class Leaderboard;
}

class Leaderboard : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;
    Ui::Leaderboard *ui;
    QString percentSpend;
    QString percentSave;
    LeaderboardHandler cReader;
    LeaderboardHandler lHandler;

public:
    explicit Leaderboard(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Leaderboard();
    void updateScreenBalance();
    void getCustomerAmountsave();
    void getCustomerAmountspend();
    void getSavePercentage();
    void getSpendPercentage();
    //void tableWidgetDisplay();
    void displayTables();

private slots:
    void on_back_clicked();



signals:
    void menuClicked();
};



#endif // LEADERBOARD_H
