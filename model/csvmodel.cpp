#include "csvmodel.h"

CsvModel::CsvModel(int id)
{
    this->id = id;
}

CsvModel::~CsvModel() {

}

void CsvModel::printInfo() const{
    cout << "Normal Model class" << endl;
}

int CsvModel::getID() const {
    return this->id;
}
