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

private:
    int OrdCoord(const Coord &a) const
    {
        return SpaceCount(a.cross) + 10* SpaceCount(a.down);
    }

};

class BCTTT_EXPORT BcTTT
{
public:
    BcTTT();
    bool isFinished() const {return false;}
    bool isEmpty(const Coord &coord) const
    {
        return false;
        //auto mark= field_.find(coord);
        //return mark == field_.end();
    }

    void setSpot(Coord coord, MarkType mark) {
        //field_.emplace(coord,mark);
    }

private:
    //std::map<Coord,MarkType,Coord> field_;//(ordCoord);

};

#endif // BCTTT_H
