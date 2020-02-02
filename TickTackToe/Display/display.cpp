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
    qreal t,b,l,r;
    m_grid->getContentsMargins(&l,&t,&r,&b);
    QPointF pos{ event->pos()};
    int x = (pos.rx()-10) / m_width;
    int y = (pos.ry()-10) / m_width;

    if (x >2 || y > 2 ||  x <0 || y < 0)
    {
        std::cerr << "Out of bounds click " << pos.rx() << ", " << pos.ry() << "\n";
        return;
    }

    if (auto item = dynamic_cast<BoxItem*>(m_grid->itemAt(x,y)->graphicsItem()))
    {
       std::cerr<<"At Pos: " << x << ", " << y << "\n";
       (void)item;
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
