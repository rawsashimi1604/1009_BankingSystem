#ifndef CSVMODEL_H
#define CSVMODEL_H

#include <iostream>
#include <vector>

/**
 *  A CsvModel is an abstract class that can be extended to signify a data model that can be stored in a CSV format.
 *
**/

class CsvModel
{

protected:
    int id;

public:
    CsvModel(int id);
    virtual ~CsvModel();

    virtual std::vector<std::string> getCsvFormat() const = 0;

    int getID() const;

};

#endif // CSVMODEL_H
