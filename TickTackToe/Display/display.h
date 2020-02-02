#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsWidget>
#include <QGraphicsGridLayout>

#include "play.h"

class Display : public QGraphicsWidget
{
    Q_OBJECT

    int m_width{};
    QGraphicsGridLayout *m_grid {};

    Play m_game;
public:
    Display(QGraphicsWidget *parent = nullptr);
    ~Display();

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;


    void setGame(Play &&game);
};
#endif // DISPLAY_H
