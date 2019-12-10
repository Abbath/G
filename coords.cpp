#include "coords.hpp"

#include <defs.hpp>

Coords::Coords(int _x, int _y) : x(_x), y(_y) {}

int Coords::X() const { return x; }

int Coords::Y() const { return y; }

void Coords::X(int _x) { x = _x; }

void Coords::Y(int _y) { y = _y; }

void Coords::translate(int dx, int dy) {
  x += dx;
  y += dy;
  if (x < 0) {
    x = FIELD_WIDTH - std::abs(x);
  }
  if (x >= FIELD_WIDTH) {
    x = x - FIELD_WIDTH;
  }
  if (y < 0) {
    y = FIELD_HEIGHT - std::abs(y);
  }
  if (y >= FIELD_HEIGHT) {
    y = y - FIELD_HEIGHT;
  }
}

double Coords::distance(Coords a) {
  return std::sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
}

