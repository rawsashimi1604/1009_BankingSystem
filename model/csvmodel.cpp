#include "csvmodel.h"

CsvModel::CsvModel(int id)
{
    this->id = id;
}

CsvModel::~CsvModel() {

}

void CsvModel::printInfo() const{
    std::cout << "Normal Model class" << std::endl;
}

int CsvModel::getID() const {
    return this->id;
}
