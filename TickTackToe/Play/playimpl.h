#ifndef IMPL_H
#define IMPL_H

#include <play.h>

#include <vector>
#include <functional>

class Play::Impl
{
public:
    Impl();

    Mark field_[9]{};
    const std::vector<Spot> moves_ {
        Spot::Center(),
        Spot::FromIndex(0),
        Spot::FromIndex(2),
        Spot::FromIndex(6),
        Spot::FromIndex(8),
        Spot::FromIndex(7),
        Spot::FromIndex(1),
        Spot::FromIndex(3),
        Spot::FromIndex(5),
    };
    void set(const Spot &spot, const Mark &mark);
    Mark getSpot(const Spot &spot) const;
    bool isFinished() const;
    bool isEmpty(const Spot &spot) const;
    Spot findBestMove(std::function<bool(const Spot&)> check);
    bool isWinningMove(const Spot &spot, Mark mark) const;

};

#endif // IMPL_H
