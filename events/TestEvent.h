#include "Event.h"

class TestEvent : public Event {
public:
    const std::string& msg;
    explicit TestEvent(const std::string& s) : msg(s) {};
};

class CollisionEvent : public Event {
public:
	int force;
    explicit CollisionEvent(int force) : force(force) {};
};