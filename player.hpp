#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <coords.hpp>

class Player {
  Coords coords;
  int hp;
public:
  Player(Coords c, int _hp);
  Coords getCoords() const;
  void setCoords(const Coords &value);
  int getHp() const;
  void setHp(int value);
  void step(int x, int y);
};

#endif // PLAYER_HPP
