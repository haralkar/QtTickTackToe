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
    static Spot FromIndex(unsigned int idx)
    {
        if (idx >=9)
            return Center();
        Spot out;
        out.down_ = (Side) (idx%3);
        out.cross_ = (Side) (idx/3);
        return out;
    }

   bool sameAs(Spot const &other) const;

   Spot setSpot(Side cross, Side down);
   std::pair<Spot,Spot> left(Spot const &here) const;
};

class PLAY_EXPORT Play
{
public:
    Play();
    ~Play();

    bool isFinished() const ;
    bool isEmpty(const Spot &spot) const;
    void setSpot(const Spot &spot, const Mark &mark);
    Mark getSpot(const Spot &spot) const;

    bool isWinningMove(Spot const &spot, Mark mark) const;
    Spot findBestMove() const;
private:
    class Impl;
    Impl *impl_{};
};

#endif // PLAY_H
