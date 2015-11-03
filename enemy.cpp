#include<enemy.h>
#include <QGraphicsScene>
#include <Qtimer>
#include <QDebug>
#include<QPixmap>
#include<stdlib.h>

#include"player.h"



Enemy::Enemy():QObject(), QGraphicsPixmapItem()
{
     setPixmap(QPixmap(":/Enemy.png"));
    //set pos
    int random_numberx = rand() %200;
    int random_numbery = rand() %200;
    setPos(random_numberx,random_numbery);


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(2500);




}

void Enemy::move()
{
    setPos(x(),y()+60);
}


