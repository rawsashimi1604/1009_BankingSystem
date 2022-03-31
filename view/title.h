#ifndef TITLE_H
#define TITLE_H

#include <QWidget>

#include "view/register.h"
#include "view/login.h"

namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(QWidget *parent = nullptr);
    ~Title();

private slots:
    void on_createAcc_clicked();
    void on_login_clicked();
    void moveMenu();

private:
    Ui::Title *ui;
    Register reg;
    Login login;
};

#endif // TITLE_H
