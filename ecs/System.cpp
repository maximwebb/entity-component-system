#include <iostream>
#include <utility>
#include "System.h"
#include <functional>


// TODO: Figure out how to write something like Subscribe<MoveEvent>(System::TheNameOfTheFunction)
System::System(Manager& m) : id(getNextId()), m(m) {
//    std::function<bool(System, Event&)> f = [=](System s, Event& e) { return s.RespondToEvent(e); };
//    std::bind(f, this);
    auto k = &System::RespondToEvent;
//    std::forward<System>(k);
    Subscribe<Event, &System::RespondToEvent>();
}

