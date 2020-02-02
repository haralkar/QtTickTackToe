#ifndef BOX_H
#define BOX_H

#include <QGraphicsLayoutItem>
#include <QGraphicsItem>
#include <QPixmap>


class BoxItem : public QGraphicsLayoutItem, public QGraphicsItem
{
    int m_X{};
    int m_Y{};
    enum class MarkType{
        Unmarked,
        Xmark,
        Omark,
    };
    MarkType m_mark{MarkType::Unmarked};

public:
    BoxItem(int x, int y, QGraphicsItem *parent = nullptr);

    void setGeometry(const QRectF &rect) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void markX();
    void markO();
private:
    QPixmap m_pix_X{};
    QPixmap m_pix_L{};
    QPixmap m_pix_O{};
};

#endif // BOX_H
