#ifndef MODEL_H
#define MODEL_H

#include <iostream>

using namespace std;

class Model
{
public:
    Model();
    virtual ~Model();
    virtual void printInfo() const;

};

#endif // MODEL_H
