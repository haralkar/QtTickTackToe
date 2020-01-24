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
};




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
