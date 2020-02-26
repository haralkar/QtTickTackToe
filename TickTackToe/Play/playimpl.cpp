#include "playimpl.h"

#include <mark.h>
//#include <mark.cpp>

#include <iostream>

Play::Impl::Impl()
{

}

void Play::Impl::clear()
{
   for (auto i = 0; i < FieldSize; ++i)
       field_[i] = Mark::Empty;
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

std::pair<Spot,bool> Play::Impl::findMove(Mark const &mark, std::function<bool (const Spot &)> check) const
{
    const bool haveCenter { getSpot(Spot::Center()) == mark};
    for (auto [x,o]:  moves_)
    {
        auto pick { haveCenter? o:x};
        if (check(pick))
            return {pick,true};
    }

    // shouldnt happen unless the grid is full:
    return {Spot{}, false};
}

std::pair<Spot,bool> Play::Impl::findBestMove(const Mark &mark) const
{
    std::cerr << "Winnig move ";
    Mark checking {mark};
    do
    {
        std::cerr << "check " << (checking == Mark::X? 'X':'O') << "\n";
        if (auto out = findMove( checking, [&](Spot const &spot){ return isWinningMove(spot,checking);})
            ;out.second)
        {
            return out;
        }
        std::cerr << "No direct win, lets defense ";
        ++checking;
    } while (checking != mark);

    if (isEmpty(Spot::Center()))
        return {Spot::Center(),true};

    //*
    std::cerr << "\nCheck corner/side";
    auto other = *this;
    auto theirMark { ++mark };
    auto cs{Corners()};
    for ( auto it : cs)//{cs.begin()}; it != cs.end(); std::find_if(it, std::end(cs), [&](Spot const &spot){return isEmpty(spot);}))
    {
        if (!isEmpty(it))
            continue;
        other.set(it,theirMark);
        auto bm = other.findBestMove(theirMark);
        if (bm.second && other.isWinningMove(bm.first, theirMark))
            return bm;//{it,true};
        other.set(it, Mark::Empty);
    }
    // */


    std::cerr << " ''random'' move\n";
    return findMove( mark, [&](Spot const &spot){ return isEmpty(spot);});
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


std::vector<Spot> spotify(int a, int b, int c) {return {Spot::FromIndex(a),Spot::FromIndex(b),Spot::FromIndex(c)};}
