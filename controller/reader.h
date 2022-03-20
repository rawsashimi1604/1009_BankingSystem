#ifndef READER_H
#define READER_H

#include <iostream>

using namespace std;

class Reader
{
public:
    Reader();
    virtual void printHello() = 0;
};

#endif // READER_H
