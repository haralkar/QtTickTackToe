#include "playimpl.h"
#include <iostream>

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
//#include <optional>  std:<Spot> stuff;

std::pair<Spot,bool> Play::Impl::findMove(std::function<bool (const Spot &)> check) const
{
    for (auto m:  moves_)
    {
        if (check(m))
            return {m,true};
    }

    // shouldnt happen unless the grid is full:
    return {Spot{}, false};
}

std::pair<Spot,bool> Play::Impl::findBestMove(const Mark &mark) const
{
    auto block = ++mark;
    if (auto out = findMove( [&](Spot const &spot){ return isWinningMove(spot, block);})
            ;out.second)
        return out;

    if (auto out = findMove( [&](Spot const &spot){ return isWinningMove(spot,mark);})
            ;out.second)
        return out;
    else
    {
        return findMove( [&](Spot const &spot){ return isEmpty(spot);});
    }
}

bool Play::Impl::isWinningMove(const Spot &spot, Mark mark) const
{
    if (!isEmpty(spot))
        return false;

    for (auto row : winningIndeces_)
    {
        if (find(row.begin(), row.end(), spot) == row.end())
            continue;

        if (std::all_of(row.begin(), row.end(), [&](Spot const s){ return s == spot || getSpot(s) == mark ;}))
            return true;
    }
    return false;
}

