#include "play.h"


class Play::Impl {
public:
    Mark field_[9]{};

    void set(const Spot &spot, const Mark &mark)
    {
        field_[spot.GetIndex()] = mark;
    }
    Mark getSpot(const Spot &spot) const
    {
        return field_[spot.GetIndex()];
    }
    bool isEmpty(const Spot &spot) const
    {
        return getSpot(spot) == Mark::Empty;
    }
    Spot findBestMove()
    {
        Spot pick = Spot::Center();
        if (isEmpty(pick))
            return Spot{}.setSpot(Side::Center, Side::Center);
        else
            return Spot{}.setSpot(Side::Left, Side::Left);
    }
    bool isWinningMove(const Spot &spot, Mark mark) const
    {
        if (!isEmpty(spot))
            return false;
        (void) spot;
        (void) mark;
        return true;
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
    return false;
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
