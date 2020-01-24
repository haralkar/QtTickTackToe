#ifndef PLAY_H
#define PLAY_H

#include "Play_global.h"

enum class Side
{
    Left,
    Center,
    Right,
};
struct Spot
{
    Side cross_;
    Side down_;

    static Spot Center() {return Spot{Side::Center, Side::Center};}
};

class PLAY_EXPORT Play
{
public:
    Play();

    bool isFinished() const ;
    bool isEmpty(const Spot &spot) const;
};

#endif // PLAY_H
