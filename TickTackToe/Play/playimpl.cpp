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
        std::cerr << "Spot checking " << (int)m.cross_ << ", " << (int)m.down_ << "\n";
        if (check(m))
            return {m,true};
    }

    // shouldnt happen unless the grid is full:
    return {Spot{}, false};
}

std::pair<Spot,bool> Play::Impl::findBestMove(const Mark &mark) const
{
    return findMove( [&](Spot const &spot){ return isWinningMove(spot,mark);});
}

bool Play::Impl::isWinningMove(const Spot &spot, Mark mark) const
{
    if (!isEmpty(spot))
        return false;

    std::cerr << "iWM  checking "<< (mark == Mark::X ? 'X':'O') << " " << (int)spot.cross_ << ", " << (int)spot.down_ << "\n";
    auto current = winningIndeces_.begin();
    auto findNext = [&](){return find_if(current, winningIndeces_.end(), [&spot](std::vector<Spot> row){return true;/*find(row.begin(),row.end(),spot)!= row.end();*/});};
    int failover = 4;
    for (; current != winningIndeces_.end(); current = findNext())
    {
        std::cerr << "Lookin at row: ";
        for_each(current->begin(), current->end(), [](const Spot &m){ std::cerr << (int)m.cross_ << ", " << (int)m.down_ << "; "; });
        std::cerr << "\n";

        if (std::all_of(current->begin(), current->end(), [&](Spot const s){ return s == spot || getSpot(s) == mark ;}))
            return true;

        if (current == winningIndeces_.end())
            return false;

        failover--;
        if (failover <= 0)
        {
            std::cerr << "Failing at checking best move!";
            return false;
        }
    }
    return false;
}

