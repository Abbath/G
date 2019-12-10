#include "shit.hpp"

int Shit::getId() const { return id; }

void Shit::setId(int value) { id = value; }

bool Shit::operator==(const Shit &a) { return id == a.id; }

Shit::Shit(int _id, Coords c) : id(_id), coords(c) {}
