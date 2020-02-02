#include "boxitem.h"


#include <QGradient>
#include <QPainter>

BoxItem::BoxItem(int x, int y, QGraphicsItem *parent)
 : QGraphicsLayoutItem(), QGraphicsItem(parent)
 , m_X(x), m_Y(y)
{
    m_pix_X=QPixmap(QLatin1String(":/images/images/cross.png"));
    m_pix_O=QPixmap(QLatin1String(":/images/images/oohh.png"));

    setGraphicsItem(this);
}

void BoxItem::setGeometry(const QRectF &rect)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(rect);
    setPos(rect.topLeft());
}

QSizeF BoxItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        return m_pix_O.size();//*3 + QSize(30,30);
    case Qt::MaximumSize:
        return QSizeF(1000,1000);
    default:
        break;
    };
    return constraint;
}

QRectF BoxItem::boundingRect() const
{
   return QRectF(QPointF(0,0), geometry().size());
}

void BoxItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   Q_UNUSED(widget);
   Q_UNUSED(option);

    QRectF frame(QPointF(m_X*30, m_Y*30), geometry().size());
    //const QSize psSize = m_pix.size();
    QGradientStops stops;

    QPointF pixpos { 0, 0};

    painter->drawPixmap(pixpos, m_pix_O);

}
