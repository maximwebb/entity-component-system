#pragma once
#include "Entity.h"

struct Component {
private:
    // Does it make sense to have this as stored as an Entity?
    Entity entity_id = 0;

    friend class Manager;

public:
    virtual void Print() {
        std::cout << "blah" << std::endl;
    }
};