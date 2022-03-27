#include "register.h"
#include "ui_register.h"

register_2::register_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::register_2)
{
    ui->setupUi(this);
}

register_2::~register_2()
{
delete ui;
}
