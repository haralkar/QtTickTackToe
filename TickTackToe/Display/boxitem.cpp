#include "boxitem.h"


#include <QGradient>
#include <QPainter>

BoxItem::BoxItem(QGraphicsItem *parent)
 : QGraphicsLayoutItem(), QGraphicsItem(parent)
{
    m_pix=QPixmap(QLatin1String(":/images/x.png"));
    setGraphicsItem(this);
}

void BoxItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   Q_UNUSED(widget);
   Q_UNUSED(option);

    QRectF frame(QPointF(0,0), geometry().size());
    //const QSize psSize = m_pix.size();
    QGradientStops stops;

    QPointF pixpos { 0, 0};

    painter->drawPixmap(pixpos, m_pix);

}
