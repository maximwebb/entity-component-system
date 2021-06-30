cmake_minimum_required(VERSION 3.17)
project(ecstest)

set(CMAKE_CXX_STANDARD 20)

include_directories(ecs)
include_directories(events)

file(GLOB ECS
        ecs/*.h
        ecs/*.cpp)

file(GLOB EVENT
        events/*.h
        events/*.cpp)

add_executable(ecstest main.cpp ${ECS} ${EVENT} ecs/Entity.h ecs/Manager.h ecs/Component.h ecs/Group.h ecs/System.h events/TestEvent.h ecs/System.cpp ecs/Manager.cpp events/Event.h)