#include "goods.hpp"

int Goods::getValue() const { return value; }

void Goods::setValue(int value) { value = value; }

Coords Goods::getCoords() const { return coords; }

void Goods::setCoords(const Coords &value) { coords = value; }

Goods::Goods(int _id, Coords c, int _v) : Shit(_id, c), value(_v) {}
