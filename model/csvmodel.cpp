#include "csvmodel.h"

CsvModel::CsvModel(int id)
{
    this->id = id;
}

CsvModel::~CsvModel() {

}



int CsvModel::getID() const {
    return this->id;
}
