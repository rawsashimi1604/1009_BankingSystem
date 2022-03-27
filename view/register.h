#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui {
class register_2;
}

class register_2 : public QWidget
{
    Q_OBJECT

public:
    explicit register_2(QWidget *parent = nullptr);
    ~register_2();

private:
    Ui::register_2 *ui;
};

#endif // REGISTER_H
