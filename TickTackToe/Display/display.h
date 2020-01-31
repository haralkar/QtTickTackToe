#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsWidget>

//QT_BEGIN_NAMESPACE
//namespace Ui { class Display; }
//QT_END_NAMESPACE

class Display : public QGraphicsWidget
{
    Q_OBJECT

public:
    Display(QGraphicsWidget *parent = nullptr);
    ~Display();
};
#endif // DISPLAY_H
