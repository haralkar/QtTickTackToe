#include <iostream>

#include "display.h"
#include "ui_display.h"
#include "boxitem.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsSceneMouseEvent>

Display::Display(QGraphicsWidget *parent )
    : QGraphicsWidget(parent, Qt::Window)
{
    QGraphicsLinearLayout *windowLayout {new QGraphicsLinearLayout(Qt::Vertical)};

    m_grid = new QGraphicsGridLayout();//windowLayout);
    m_grid->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    auto addItem {[&] (int x, int y){
        BoxItem *item = new BoxItem(0,0);
        m_grid->addItem(item,x,y,1,1);

        m_width = m_width== 0? item->geometry().width():m_width;
        }};

    for (int x= 0; x < 3; x++ )
    {
        for (int y= 0; y < 3; y++ )
        {
            addItem(x,y);
        }
    }
    if (m_width == 0)
        m_width = 65;  // Taking the liberty of straight up guessing width and item space between items.

    windowLayout->addItem(m_grid);
    setLayout(windowLayout);
}

Display::~Display()
{
}



void Display::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos{ event->pos()};
    int col = (pos.rx()-10) / m_width; // rudely assuming observed values.
    int row = (pos.ry()-10) / m_width;

    if (col >2 || row > 2 ||  col <0 || row < 0)
    {
        std::cerr << "Out of bounds click " << pos.rx() << ", " << pos.ry() << "\n";
        return;
    }

    if (m_game.isFinished())
    {
        std::cerr<<"Game over";
        return;
    }

    if (auto item = dynamic_cast<BoxItem*>(m_grid->itemAt(row,col)->graphicsItem()))
    {
       std::cerr<<"At Pos: " << row << col << ", " << "\n";

       item->markX();
       m_game.setSpot(Spot::FromIndex(col+row*3),Mark::X);
       Spot oh = m_game.findBestMove();
       m_game.setSpot(oh,Mark::O);
       int c = (unsigned int)oh.down_;
       int r = (unsigned int)oh.cross_;
       auto itemO = dynamic_cast<BoxItem*>(m_grid->itemAt(r,c)->graphicsItem());
       itemO->markO();
       m_grid->invalidate();
    }
    else
    {
        std::cerr << "NOPES\n";
    }
    return;
}


void Display::setGame(Play &&game)
{
    m_game = game;
}
