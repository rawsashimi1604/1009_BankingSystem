#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>

#include "bankingapp.h"

namespace Ui {
class Transfer;
}

class Transfer : public QWidget
{
    Q_OBJECT

public:
    explicit Transfer(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Transfer();
    void updateScreenBalance();

private:
    Ui::Transfer *ui;
    BankingApp* bankApp;

signals:
    void menuClicked();
private slots:
    void on_back_clicked();
};

#endif // TRANSFER_H
