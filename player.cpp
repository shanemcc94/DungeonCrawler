#include "player.h"
#include "Arrow.h"
#include "mainwindow.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QDebug>


Player::Player(): QGraphicsPixmapItem()
{

    setPlayerType(0);//sets player to sword+shield

    setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_2.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(x(),y()+240);//starts player in the centre of the room


}

/*TODO :
        Create an arrow class that fires arrows when
        player has bow

        figure out how to get player animations to work with
        setPlayerType if Statement
        i.e when bow selected it points in the direction of movement
            else player just has sword+sheild

        figure out some sort of attack class for damage and attack animation
        note:needs threads to work*/


void Player::setPlayerType(int newPlayerType)
{
    static int playerType;
    playerType = newPlayerType;
 }

int Player::getPlayerType(){
    return playerType;
}


void Player::keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Left){

        setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_2.png"));
        if(pos().x() >-240){
            move(-10,0);
        }
    }
    else if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/Bow_Player_images/Player_Bow_Right.png"));
        if(pos().x() <240){
            move(10,0);
        }
    }
    else if(event->key() == Qt::Key_Up){
        setPixmap(QPixmap(":/Bow_Player_images/Player_Bow_UP.png"));
        if(pos().y() >0){
           move(0,-10);
        }
    }
    else if(event->key() == Qt::Key_Down){
        setPixmap(QPixmap(":/Bow_Player_images/Player_Bow_Down.png"));


        if(pos().y() <440){
           move(0,10);
        }
    }
    else if(event->key() == Qt::Key_1)
    {
        setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_1.png"));//sets player to sword + shield
        setPlayerType(1);
    }
    else if(event->key() == Qt::Key_2)
    {

        setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_2.png"));//sets player to bow and arrow
        setPlayerType(2);
    }

    else if(event->key()== Qt::Key_Space){
        arrow = new Arrow;
        arrow->setPos(x(),y());
        scene()->addItem(arrow);
        qDebug()<<"Shots fired";





    }
}

void Player::move(int newX, int newY){//method adds a pixel distance to player
    setPos(x()+newX,y()+newY);
}



int Player::getxPos()
{
    return this->pos().x();
}

int Player::getyPos()
{
    return this->pos().y();
}


