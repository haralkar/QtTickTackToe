#include "board.h"

Board::Board(QWidget *parent) : QWidget(parent)
{
    //for (auto idx = 0; idx < 10 ;idx++  ) m_checkBoxes.emplace(idx, idx/3,idx%3);
}

#include <iostream>
void Board::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    std::cerr << "click" << std::endl;
    std::cerr << std::flush;
    return;
}
