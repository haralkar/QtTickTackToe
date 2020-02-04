#include "playimpl.h"

Play::Impl::Impl()
{

}

void Play::Impl::set(const Spot &spot, const Mark &mark)
{
    field_[spot.GetIndex()] = mark;
}

Mark Play::Impl::getSpot(const Spot &spot) const
{
    return field_[spot.GetIndex()];
}

bool Play::Impl::isFinished() const
{
    for ( auto s : field_)
    {
        if (s == Mark::Empty)
        {
            return false;
        }
    }
    return true;
}

bool Play::Impl::isEmpty(const Spot &spot) const
{
    return getSpot(spot) == Mark::Empty;
}

Spot Play::Impl::findBestMove(std::function<bool (const Spot &)> check)
{
    for (auto m:  moves_)
    {
        if (check(m))
            return m;
    }

    // shouldnt happen unless the grid is full:
    return Spot::Center();
}

bool Play::Impl::isWinningMove(const Spot &spot, Mark mark) const
{
    // At least it is valid and could be on the best path
    return isEmpty(spot);
}

