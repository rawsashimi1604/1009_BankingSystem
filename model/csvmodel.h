#ifndef CSVMODEL_H
#define CSVMODEL_H

#include <iostream>
#include <vector>

/**
 * A CsvModel signifies any Model object that is represented in the database
 *
 * It contains methods and attributes of any database Model object.
 */
class CsvModel
{

protected:
    int id;                                                                 // ID of object in database

public:
    CsvModel(int id);                                                       // Constructs CSV model object with ID
    virtual ~CsvModel();                                                    // Destructs CSV model object
    virtual std::vector<std::string> getCsvFormat() const = 0;              // Pure virtual function, get CsvFormat as vector
    int getID() const;                                                      // Getter function for ID

};

#endif // CSVMODEL_H
