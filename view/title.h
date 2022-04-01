#ifndef TITLE_H
#define TITLE_H

#include <QWidget>

#include "bankingapp.h"
#include "view/registeracc.h"
#include "view/login.h"

namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(BankingApp* bankApp, QWidget *parent = nullptr);
    ~Title();

private slots:
    void on_createAcc_clicked();
    void on_login_clicked();
    void moveMenu();

private:
    BankingApp* bankApp;
    Ui::Title *ui;
    RegisterAcc reg;
    Login login;
};

#endif // TITLE_H
