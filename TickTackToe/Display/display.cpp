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
        m_width = 90;

    //linear->setStretchFactor(item,1);
    windowLayout->addItem(m_grid);
    setLayout(windowLayout);
}


#include <iostream>

void Display::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qreal t,b,l,r;
    m_grid->getContentsMargins(&t,&b,&l,&r);
    QPointF pos1{ event->lastScenePos()};
    QPointF pos{ event->pos()};
    std::cerr << pos.rx() << " " << pos.ry()<<"\n";
    std::cerr << pos1.rx() << " " << pos1.ry()<<"\n";
    int x = (pos.rx()-l) / m_width;
    int y = (pos.ry()-t) / m_width;
    if (x >2 || y > 2 ||  x <0 || y < 0)
    {
        BoxItem it(4,4);
        qreal t,b,l,r;
        it.getContentsMargins(&t,&b,&l,&r);
        std::cerr << " item thingy" << (int)t << ", " <<  (int)b << ", " << (int)r << ", " << (int)l << "\n";
        std::cerr << "Out of bounds click " << pos.rx() << ", " << pos.ry() << "(width "<< it.geometry().width() <<"\n";
        return;
    }

    std::cerr<< "Checking point " << x << ", " << y << "\n";
    //if (QGraphicsGridLayout *layout = dynamic_cast<QGraphicsGridLayout*>(this->layout()))
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

Display::~Display()
{
}

