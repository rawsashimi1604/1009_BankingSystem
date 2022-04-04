#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>

#include "bankingapp.h"

namespace Ui {
class History;
}

class History : public QWidget
{
    Q_OBJECT

public:
    explicit History(BankingApp* bankApp, QWidget *parent = nullptr);
    ~History();
    void updateScreenBalance();

private:
    Ui::History *ui;
    BankingApp* bankApp;

signals:
    void menuClicked();
private slots:
    void on_back_clicked();
};

#endif // HISTORY_H
