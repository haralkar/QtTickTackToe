#include "bcttt.h"
//*

QT_BEGIN_NAMESPACE

BcTTT::BcTTT()
{
    for (int i = 0; i<9; i++)
        field_ [i] = MarkType::Empty;
}

bool BcTTT::isFinished() const
{
    return false;
}
bool BcTTT::isEmpty(const Coord &coord) const
{
    return field_[coord.OrdCoord()] == MarkType::Empty;
}

void BcTTT::setSpot(Coord coord, MarkType mark)
{
    field_[coord.OrdCoord()] = mark;
}

QT_END_NAMESPACE
// */
