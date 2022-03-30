#include "view.h"

View::View()
{

}
void View::on_back_clicked()
{
    emit menuClicked();
}
