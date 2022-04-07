#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QWidget>

#include "bankingapp.h"

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
    explicit Leaderboard(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Leaderboard();
    void updateScreenBalance();

private slots:
    void on_back_clicked();



signals:
    void menuClicked();
};



#endif // LEADERBOARD_H
