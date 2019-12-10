#ifndef GOODS_HPP
#define GOODS_HPP

#include <shit.hpp>

class Goods : public Shit {
  int value;

public:
  Goods() : Goods(0, {0, 0}, 100) {}
  Goods(int _id, Coords c, int _v);
  int getValue() const;
  void setValue(int value);
  Coords getCoords() const;
  void setCoords(const Coords &value);
  friend bool operator==(const Goods a, const Goods b);
};

#endif // GOODS_HPP
