#include "csvmodel.h"

/**
 * Constructs CSV model object with ID
 *
 * @param id -> id of CSV model object in database
 *
 */
CsvModel::CsvModel(int id)
{
    this->id = id;
}

/**
 * Destructs CSV model object
 *
 * @param None
 *
 */
CsvModel::~CsvModel() {

}

/**
 * Getter function for ID
 *
 * @param None
 * @return CSVModel object database ID.
 */
int CsvModel::getID() const {
    return this->id;
}
