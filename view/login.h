#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <QMainWindow>
#include "view/menu.h"
#include "controller/loginhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    Ui::Login* getUI();

private slots:
    void on_loginButton_clicked();


private:
    Ui::Login *ui;
    Menu menu;
};
#endif // LOGIN_H
