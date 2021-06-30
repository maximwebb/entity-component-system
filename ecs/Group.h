#pragma once

#include "Entity.h"
#include "Component.h"
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <iterator>

template<class... Components>
class Group {
private:
    std::vector<int32_t> entities;
    std::unordered_map<int32_t, std::tuple<Components...>> entity_tuples;

public:
    Group() : entities(std::vector<int32_t>()),
              entity_tuples(std::unordered_map<int32_t, std::tuple<Components...>>()) {

    };

    void Push(int32_t e, std::tuple<Components...> tuple) {
        entities.push_back(e);
        entity_tuples.emplace(e, tuple);
    };

    decltype(auto) Get(int32_t id) {
        auto it = entity_tuples.find(id);
        if (it != entity_tuples.end()) {
            return it->second;
        } else {
            std::cout << "Entity not contained in group" << std::endl;
            throw std::exception();
        }
    };

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int32_t;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(pointer ptr) : ptr(ptr) {};

        reference operator*() const { return *ptr; };

        pointer operator->() { return ptr; }

        Iterator& operator++() {
            ptr++;
            return *this;
        };

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        };

        friend bool operator==(const Iterator& a, const Iterator& b) { return a.ptr == b.ptr; };

        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; };

    private:
        pointer ptr;
    };

    std::vector<int32_t>::iterator begin() { return entities.begin(); };
    std::vector<int32_t>::iterator end() { return entities.end(); };
};