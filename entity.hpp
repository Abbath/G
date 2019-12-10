#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <shit.hpp>

class Entity : public Shit
{
    int hp;
    bool hunting = false;
public:
    Entity() : Entity(0, {0, 0}, 100) {}
    Entity(int _id, Coords c, int _hp);
    Coords getCoords() const;
    void setCoords(const Coords &value);
    int getHp() const;
    void setHp(int value);
    void step(int x, int y);
    bool getHunting() const;
    void setHunting(bool value);
    friend bool operator==(const Entity a, const Entity b);
};

#endif // ENTITY_HPP
