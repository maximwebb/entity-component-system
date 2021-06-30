#include <iostream>
#include <utility>
#include <Group.h>
#include <unordered_set>
#include "Manager.h"
#include "System.h"

struct Pos : public Component {
        int x;
        int y;
        int z;
        Pos() : x(0), y(0), z(0) {};
        Pos(int x, int y, int z) : x(x), y(y), z(z) {};

        void Print() {
            std::cout << "Pos: " << x << ", " << y << ", " << z << std::endl;
        }
    };

struct Mass : public Component {
    int mass;
    Mass(int mass) : mass(mass) {};

    void Print() {
        std::cout << "Mass:" << mass << std::endl;
    }
};

struct Name : public Component {
    std::string name;
    Name(std::string  name) : name(std::move(name)) {};
};

int main() {
    Manager m;
    Entity e1 = m.Create();
    Entity e2 = m.Create();
    Entity e3 = m.Create();

    m.Add<Pos>(e1, 1, 2, 3);
    m.Add<Mass>(e1, 5);
    m.Add<Mass>(e2, 20);
    m.Add<Pos>(e2, 3, 1, 4);
    m.Add<Name>(e1, "Maxim");
    m.Add<Pos>(e3, 9, 8, 7);
    m.Add<Name>(e3, "Freddie");

    // Create group joining entities with position and mass
    auto g = m.CreateGroup<Pos, Mass>();

    for (auto e : g) {
        auto [pos, mass] = g.Get(e);
        std::cout << "Entity " << e << ": " << std::endl;
        pos->Print();
        mass->Print();
    }

    System s1(m);
    System s2(m);

    return 0;
}
