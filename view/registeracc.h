#ifndef REGISTERACC_H
#define REGISTERACC_H

#include <QtWidgets>

#include "bankingapp.h"
#include "controller/registerhandler.h"
#include "utils.h"


namespace Ui {
class RegisterAcc;
}

class RegisterAcc : public QWidget
{
    Q_OBJECT

private:
    BankingApp* bankApp;
    Ui::RegisterAcc *ui;
    bool checkFlag ;

public:
    explicit RegisterAcc(BankingApp* bankApp, QWidget *parent = nullptr);
    ~RegisterAcc();

private slots:
    void on_back_clicked();

    void on_pushButton_3_clicked();

signals:
    void menuClicked();
};

#endif // REGISTERACC_H
