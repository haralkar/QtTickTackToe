#include "mark.h"


Mark operator++(Mark &other)
{
    switch (other) {
    case Mark::X: other = Mark::O; break;
    case Mark::O: other = Mark::X; break;
    default: break;
    }
    return other;
}

Mark operator++(const Mark &other)
{
    switch (other) {
    case Mark::X: return Mark::O;
    case Mark::O: return Mark::X;
    default: return Mark::Empty;
    }
}

Mark operator++(Mark &lhs, int)
{
    auto thisOne { lhs};
    lhs = ++lhs;
    return thisOne;
}
