#include "display.h"

#include <QApplication>
#include <QGraphicsView>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;

    std::cerr << " Starting up!\n";

    Display *w { new Display};
    scene.addItem(w);
    QGraphicsView view(&scene);
    view.resize(600,600);
    view.show();

    return a.exec();
}
