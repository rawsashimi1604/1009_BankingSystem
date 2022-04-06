#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>

#include "bankingapp.h"
#include "controller/transactionreader.h"

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
    void tableWidgetDisplay();

private:
    Ui::History *ui;
    BankingApp* bankApp;
    TransactionReader cReader;

private slots:
    void on_back_clicked();

signals:
    void menuClicked();

};

#endif // HISTORY_H
