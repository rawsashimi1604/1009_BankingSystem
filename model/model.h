#ifndef MODEL_H
#define MODEL_H

/**
 * @brief The Model class is an abstract class, that specifies each Model type object's behaviour
 */

#include <iostream>

class Model
{
public:
    Model();
    virtual void printInfo() const;
};

#endif // MODEL_H
