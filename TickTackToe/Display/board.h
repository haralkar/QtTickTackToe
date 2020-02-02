#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

#include "boxitem.h"

class Board : public QWidget
{
    Q_OBJECT

    std::map<int, BoxItem> m_checkBoxes{};
public:
    explicit Board(QWidget *parent = nullptr);

    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

};

#endif // BOARD_H
