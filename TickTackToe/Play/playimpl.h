#ifndef IMPL_H
#define IMPL_H

#include <play.h>

#include <vector>
#include <functional>

constexpr int FieldSize{9};

class Play::Impl
{
public:
    Impl();

    void clear();

    Mark field_[FieldSize]{};
    const std::vector<std::pair<Spot,Spot>> moves_ {
        {Spot::FromIndex(4),Spot::FromIndex(4)},
        {Spot::FromIndex(0),Spot::FromIndex(7)},
        {Spot::FromIndex(2),Spot::FromIndex(1)},
        {Spot::FromIndex(6),Spot::FromIndex(3)},
        {Spot::FromIndex(8),Spot::FromIndex(5)},
        {Spot::FromIndex(7),Spot::FromIndex(0)},
        {Spot::FromIndex(1),Spot::FromIndex(2)},
        {Spot::FromIndex(3),Spot::FromIndex(6)},
        {Spot::FromIndex(5),Spot::FromIndex(8)},
    };
    std::vector<Spot> spotify(int a, int b, int c) {return {Spot::FromIndex(a),Spot::FromIndex(b),Spot::FromIndex(c)};}
    const std::vector<std::vector<Spot>> winningIndeces_
    {
        spotify(0,1,2), // top line across
        spotify(0,4,8), // diag tl->br
        spotify(0,3,6),
        spotify(1,4,7),
        spotify(2,5,8),
        spotify(2,4,6),
        spotify(3,4,5),
        spotify(6,7,8),
    };
    void set(const Spot &spot, const Mark &mark);
    Mark getSpot(const Spot &spot) const;
    bool isFinished() const;
    bool isEmpty(const Spot &spot) const;
    //std::optional<Spot> findBestMove(std::function<bool(const Spot&)> check) const;
    std::pair<Spot,bool> findMove(Mark const &mark, std::function<bool (const Spot &)>) const;
    std::pair<Spot,bool> findBestMove(const Mark &mark) const;
    bool isWinningMove(const Spot &spot, Mark mark) const;

};

#endif // IMPL_H
