#include "play.h"
#include "playimpl.h"



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

void Play::clear()
{
  impl_->clear();
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


Spot Play::findMove(Mark const & mark) const
{
    return impl_-> findBestMove(mark).first;
}

Spot Play::findBestMove(const Mark &mark) const
{
    auto blockWith = ++mark;
    if (auto [spot, found] =  impl_->findBestMove(blockWith)
            ; found)
    {
        return spot;
    }

    return impl_->findBestMove(mark).first;
}
