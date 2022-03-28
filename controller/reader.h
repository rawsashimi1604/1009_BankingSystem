#ifndef READER_H
#define READER_H

#include "model/model.h"

class Reader
{
public:
    Reader();
    virtual Model* searchByID();

};

#endif // READER_H
