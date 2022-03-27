#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <QMainWindow>
#include "view/menu.h"
#include "controller/loginhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

    Ui::login* getUI();

private slots:
    void on_loginButton_clicked();


private:
    Ui::login *ui;
    menu menu;
};
#endif // LOGIN_H
