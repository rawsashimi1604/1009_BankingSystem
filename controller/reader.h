#ifndef READER_H
#define READER_H

#include <iostream>
#include "model/model.h"


using namespace std;

class Reader
{
public:
    Reader();
    virtual void printHello() = 0;
    virtual Model* read(int id) = 0;
    virtual void write(Model* model) = 0;
};

#endif // READER_H

// controller = all the logic
// model = all the data
// view = UI

