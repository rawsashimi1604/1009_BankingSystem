#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QWidget>

namespace Ui {
class Withdraw;
}

class Withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();

private:
    Ui::Withdraw *ui;
};

#endif // WITHDRAW_H
