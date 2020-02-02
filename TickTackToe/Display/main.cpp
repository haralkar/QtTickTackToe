#include "display.h"

#include <iostream>

#include <QApplication>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;

    std::cerr << " Starting up!\n";

    Display *w { new Display};
    Play game;
    w->setGame(std::move(game));

    scene.addItem(w);
    QGraphicsView view(&scene);
    view.resize(600,600);
    view.show();

    return a.exec();
}
