#ifndef PLAY_H
#define PLAY_H

#include "Play_global.h"

enum class Mark {
    Empty,
    X,
    O,
};

enum class Side : unsigned int
{
    Left = 0,
    Center,
    Right,
};
struct Spot
{
    Side cross_;
    Side down_;

    static Spot Center() {return Spot{Side::Center, Side::Center};}
    unsigned int GetIndex() const
    {
        return (unsigned int)down_ + 3*(unsigned int)cross_;
    }
};

class PLAY_EXPORT Play
{
public:
    Play();

    bool isFinished() const ;
    bool isEmpty(const Spot &spot) const;
    void setSpot(const Spot &spot, const Mark &mark);
private:
    class Impl;
    Impl *impl_;
};

#endif // PLAY_H
