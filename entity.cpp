#include "entity.hpp"

Coords Entity::getCoords() const { return coords; }

void Entity::setCoords(const Coords &value) { coords = value; }

int Entity::getHp() const { return hp; }

void Entity::setHp(int value) { hp = value; }

void Entity::step(int x, int y) { coords.translate(x, y); }

bool Entity::getHunting() const
{
    return hunting;
}

void Entity::setHunting(bool value)
{
    hunting = value;
}

Entity::Entity(int _id, Coords c, int _hp) : Shit(_id, c), hp(_hp) {}
