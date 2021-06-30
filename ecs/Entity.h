#pragma once

struct Entity {
    inline Entity(int id) : id(id) {};

    int32_t id;

    operator int32_t () const {
        return id;
    }
};