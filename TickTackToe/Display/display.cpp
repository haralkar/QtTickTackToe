#include "display.h"
#include "ui_display.h"
#include "boxitem.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>

Display::Display(QGraphicsWidget *parent )
    : QGraphicsWidget(parent, Qt::Window)
{
    QGraphicsLinearLayout *windowLayout {new QGraphicsLinearLayout(Qt::Vertical)};
    QGraphicsLinearLayout *linear {new QGraphicsLinearLayout(windowLayout)};

    QGraphicsGridLayout *grid = new QGraphicsGridLayout(windowLayout);
    BoxItem *item = new BoxItem;
    grid->addItem(item,0,0,1,1);
    //linear->setStretchFactor(item,1);
    windowLayout->addItem(grid);
    setLayout(windowLayout);
}

Display::~Display()
{
}

