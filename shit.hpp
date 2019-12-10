#ifndef SHIT_HPP
#define SHIT_HPP

#include <coords.hpp>
#include <defs.hpp>

class Shit
{
protected:
    Coords coords = {FIELD_WIDTH/2, FIELD_HEIGHT/2};
    int id = -1;
public:
    Shit(int _id, Coords c);
    int getId() const;
    void setId(int value);
    bool operator==(const Shit& a);
};

#endif // SHIT_HPP
