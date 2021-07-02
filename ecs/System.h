#pragma once
#include <cstdint>
#include <functional>
#include <iostream>
#include <typeindex>
#include <utility>
#include "TestEvent.h"
#define HANDLER(func) [this](auto&& e) { func(std::forward<const Event&>(e)); }

class Manager;

class System {

	typedef std::function<void(const Event&)> EventHandler;

    int getNextId() {
        static int next_id = 0;
        return next_id++;
    }

public:
    int32_t id;
    Manager& m;

    explicit System(Manager&);

    template<typename T>
	void Subscribe(EventHandler handler) {
		std::type_index type_id = typeid(T);
		SubscribeInner(type_id, std::move(handler));
	}

	void SubscribeInner(std::type_index type_id, EventHandler f);

    virtual void Update(Event e) {
        std::cout << "Received event in base class" << std::endl;
    }

};

class TestSystem1 : public System {
public:
    TestSystem1(Manager& m) : System(m) {
        Subscribe<TestEvent>(HANDLER(HandleTestEvent));
    }

    void HandleTestEvent(const Event& e) {
    	auto d = static_cast<const TestEvent&>(e);
        std::cout << "Received test event in Test System 1" << std::endl;
        std::cout << "Text: " << d.msg << std::endl;
    }
};

class TestSystem2: public System {
public:
    TestSystem2(Manager& m) : System(m) {
        Subscribe<TestEvent>(HANDLER(HandleTestEvent));
        Subscribe<CollisionEvent>(HANDLER(HandleCollisionEvent));
    }


    void HandleTestEvent(const Event& e) {
    	auto d = static_cast<const TestEvent&>(e);
        std::cout << "Received test event in Test System 2" << std::endl;
        std::cout << "Text: " << d.msg << std::endl;
    }

    void HandleCollisionEvent(const Event& e) {
    	auto d = static_cast<const CollisionEvent&>(e);
        std::cout << "Received collision event in Test System 2" << std::endl;
        std::cout << "Force: " << d.force << std::endl;
    }
};