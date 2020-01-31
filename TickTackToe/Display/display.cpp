#include "display.h"
#include "ui_display.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>

Display::Display(QGraphicsWidget *parent )
    : QGraphicsWidget(parent, Qt::Window)
{
    QGraphicsLinearLayout *windowLayout {new QGraphicsLinearLayout(Qt::Vertical)};
    QGraphicsLinearLayout *linear {new QGraphicsLinearLayout(windowLayout)};
}

Display::~Display()
{
}

