#ifndef ENEMY
#define ENEMY

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>


class Enemy:public QObject, public QGraphicsPixmapItem{
public:
    Enemy();
public slots:
    void move();

};












#endif // ENEMY

