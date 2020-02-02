#include "display.h"
#include "ui_display.h"
#include "boxitem.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsSceneMouseEvent>

Display::Display(QGraphicsWidget *parent )
    : QGraphicsWidget(parent, Qt::Window)
{
    QGraphicsLinearLayout *windowLayout {new QGraphicsLinearLayout(Qt::Vertical)};
    //QGraphicsLinearLayout *linear {new QGraphicsLinearLayout(windowLayout)};

    m_grid = new QGraphicsGridLayout();//windowLayout);

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

    //linear->setStretchFactor(item,1);
    windowLayout->addItem(m_grid);
    setLayout(windowLayout);
}


#include <iostream>

void Display::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos{ event->pos()};
    auto x = pos.rx() / m_width;
    auto y = pos.ry() / m_width;

    //if (QGraphicsGridLayout *layout = dynamic_cast<QGraphicsGridLayout*>(this->layout()))
    if (auto item = dynamic_cast<BoxItem*>(m_grid->itemAt(x,y)))
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

Display::~Display()
{
}

