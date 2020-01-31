#ifndef BOX_H
#define BOX_H

#include <QGraphicsLayoutItem>
#include <QGraphicsItem>
#include <QPixmap>


class BoxItem : public QGraphicsLayoutItem, public QGraphicsItem
{
public:
    BoxItem(QGraphicsItem *parent = nullptr);

    void setGeometry(const QRectF &rect) override{};
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override{};

    QRectF boundingRect() const override{};
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private:
    QPixmap m_pix{};
};

#endif // BOX_H
