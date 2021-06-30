#pragma once
#include <cstdint>
#include "Manager.h"

class System {

    int getNextId() {
        static int next_id = 0;
        return next_id++;
    }

public:
    int32_t id;
    Manager& m;

    explicit System(Manager&);

    bool RespondToEvent(Event& e) {
        std::cout << "Responeded to the event!!!" << std::endl;
        return true;
    }

    // TODO: Figure out how to write something like Subscribe<MoveEvent>(System::TheNameOfTheFunction)
    template<class T, bool(System::*F)(Event&)>
    void Subscribe() {
        std::type_index type_id = typeid(T);
        Event e;
        F;
    }

};

