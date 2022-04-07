#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>

#include "bankingapp.h"
#include "controller/transactionreader.h"
#include "utils.h"
#include "model/customer.h"

namespace Ui {
class History;
}

class History : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;
    Ui::History *ui;
    TransactionReader tReader;
    CredentialsReader cReader;

public:
    explicit History(BankingApp* bankApp, QWidget *parent = nullptr);
    ~History();
    void updateScreenBalance();
    void tableWidgetDisplay();


private slots:
    void on_back_clicked();

signals:
    void menuClicked();

};

#endif // HISTORY_H
