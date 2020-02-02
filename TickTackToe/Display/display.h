#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsWidget>
#include <QGraphicsGridLayout>

class Display : public QGraphicsWidget
{
    Q_OBJECT

    int m_width{};
    QGraphicsGridLayout *m_grid {};
public:
    Display(QGraphicsWidget *parent = nullptr);
    ~Display();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;
};
#endif // DISPLAY_H
