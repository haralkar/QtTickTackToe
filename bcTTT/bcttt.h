#ifndef BCTTT_H
#define BCTTT_H

#include "bcTTT_global.h"

enum class Space {
    Left,
    Center,
    Right
};
struct Coord {
    Space cross;
    Space down;

    static constexpr Coord center() {
        return Coord{Space::Center, Space::Center};
    }
};

class BCTTT_EXPORT BcTTT
{
public:
    BcTTT();
    bool isFinished() {return false;}
    bool isEmpty(Coord) {return true;}
};

#endif // BCTTT_H
