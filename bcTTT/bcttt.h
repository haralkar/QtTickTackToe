#ifndef BCTTT_H
#define BCTTT_H

#include "bcTTT_global.h"
#include <map>

enum class MarkType {
    Empty,
    X,
    O,
};

enum class Space {
    Left,
    Center,
    Right
};
/*constexpr*/ int SpaceCount(const Space &s)
{
    switch (s)
    {
    case Space::Left: return 0;
    case Space::Center: return 1;
    case Space::Right: return 2;
    default:
        return 999;
    }
}

struct Coord {
    Space cross;
    Space down;

    static constexpr Coord center()
    {
        return Coord{Space::Center, Space::Center};
    }
    bool operator()(const Coord &a, const Coord &b) const
    {
        return OrdCoord(a) < OrdCoord(b);
    }

    static int OrdCoord(const Coord &a)
    {
        return a.OrdCoord();
    }
    int OrdCoord() const
    {
        return SpaceCount(cross) + 3* SpaceCount(down);
    }


};

class BCTTT_EXPORT BcTTT
{
public:
    BcTTT();
    bool isFinished() const;
    bool isEmpty(const Coord &coord) const;
    void setSpot(Coord coord, MarkType mark);

private:
    MarkType field_[9];
};

BcTTT::BcTTT()
{
    for (int i = 0; i<9; i++)
        field_ [i] = MarkType::Empty;
}
bool BcTTT::isFinished() const
{
    return false;
}
bool BcTTT::isEmpty(const Coord &coord) const
{
    return field_[coord.OrdCoord()] == MarkType::Empty;
}

void BcTTT::setSpot(Coord coord, MarkType mark)
{
    field_[coord.OrdCoord()] = mark;
}



#endif // BCTTT_H
