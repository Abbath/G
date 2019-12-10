#include "player.hpp"

Coords Player::getCoords() const { return coords; }

void Player::setCoords(const Coords &value) { coords = value; }

int Player::getHp() const { return hp; }

void Player::setHp(int value) { hp = value; }

void Player::step(int x, int y) { coords.translate(x, y); }

Player::Player(Coords c, int _hp) : coords(c), hp(_hp) {}
