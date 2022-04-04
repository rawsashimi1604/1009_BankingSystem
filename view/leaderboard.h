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

public:
    explicit Leaderboard(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Leaderboard();
    void updateScreenBalance();

private slots:
    void on_back_clicked();

private:
    BankingApp* bankApp;
    Ui::Leaderboard *ui;

signals:
    void menuClicked();
};



#endif // LEADERBOARD_H
