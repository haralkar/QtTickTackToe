#include "play.h"

#include<vector>

class Play::Impl {
public:
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

    void set(const Spot &spot, const Mark &mark)
    {
        field_[spot.GetIndex()] = mark;
    }
    Mark getSpot(const Spot &spot) const
    {
        return field_[spot.GetIndex()];
    }
    bool isFinished() const
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
    bool isEmpty(const Spot &spot) const
    {
        return getSpot(spot) == Mark::Empty;
    }
    Spot findBestMove()
    {
        for (auto m:  moves_)
        {
            if (isEmpty(m))
                return m;
        }

        // shouldnt happen unless the grid is full:
        return Spot::Center();
    }
    bool isWinningMove(const Spot &spot, Mark mark) const
    {
        // At least it is valid and could be on the best path
        return isEmpty(spot);
    }
};


Spot Spot::setSpot(Side cross, Side down)
{
    cross_ = cross;
    down_ = down;
    return *this;
}

bool Spot::sameAs(const Spot &other) const
{
   return down_ == other.down_ && cross_ == other.cross_;
}



Play::Play()
    : impl_(new Impl{})
{
}

Play::~Play()
{
    delete impl_;
}

bool Play::isFinished() const
{
    return impl_->isFinished();
}

bool Play::isEmpty(const Spot &spot) const
{
    return impl_->isEmpty(spot);
}

void Play::setSpot(const Spot &spot, const Mark &mark)
{
    impl_->set(spot,mark);
}

Mark Play::getSpot(const Spot &spot) const
{
    return impl_->getSpot(spot);
}

bool Play::isWinningMove(const Spot &spot, Mark mark) const
{
    return impl_-> isWinningMove(spot, mark) ;
}

Spot Play::findBestMove() const
{
    return impl_-> findBestMove();
}
