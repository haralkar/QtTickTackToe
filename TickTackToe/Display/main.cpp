#include "display.h"

#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;


    Display *w { new Display};
    scene.addItem(w);
    QGraphicsView view(&scene);
    view.resize(600,600);
    view.show();

    return a.exec();
}
