#ifndef COORDS_HPP
#define COORDS_HPP

class Coords {
  int x;
  int y;

public:
  Coords(int _x, int _y);
  int X() const;
  int Y() const;
  void X(int _x);
  void Y(int _y);
  void translate(int dx, int dy);
  double distance(Coords a);
};

#endif // COORDS_HPP
