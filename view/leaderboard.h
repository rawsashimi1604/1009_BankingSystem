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

public:
    Leaderboard(std::string, std::string, std::string, std::string, std::string, std::string);
    explicit Leaderboard(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Leaderboard();
    void updateScreenBalance();
    void displayTables();

private slots:
    void on_back_clicked();



signals:
    void menuClicked();
};



#endif // LEADERBOARD_H
