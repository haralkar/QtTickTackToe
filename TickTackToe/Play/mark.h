#ifndef MARK_H
#define MARK_H

enum class Mark {
    Empty,
    X,
    O,
};

Mark operator++(Mark  &other);
Mark operator++(Mark const &other);
Mark operator++(Mark &lhs, int);


#endif // MARK_H
