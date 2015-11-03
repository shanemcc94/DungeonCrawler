#include "player.h"
#include <QDebug>
#include "wall.h"
#include <QMediaPlayer>
#include "arrow.h"
#include "mainwindow.h"


Player::Player(): QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_2.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(x(),y()+240);//starts player in the centre of the room
    walk = new QMediaPlayer();
    walk->setMedia(QUrl("qrc:/sounds/257276__clippysounds__two-footsteps.wav"));
    Bow = new QMediaPlayer();
    Bow->setMedia(QUrl("qrc:/sounds/209399__samulis__bow-release.mp3"));
    Sword = new QMediaPlayer();
    Sword->setMedia(QUrl("qrc:/sounds/263011__dermotte__sword-02.wav"));
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


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_2.png"));

        if(pos().x() > -230)

        move(-10,0);

    }
    else if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/Bow_Player_images/Player_Bow_Right.png"));
        if(pos().x()<240)
        move(10,0);
    }
    else if(event->key() == Qt::Key_Up){
        setPixmap(QPixmap(":/Bow_Player_images/Player_Bow_UP.png"));

        if(pos().y()> 40)
        move(0,-10);
    }
    else if(event->key() == Qt::Key_Down){
        setPixmap(QPixmap(":/Bow_Player_images/Player_Bow_Down.png"));

        if(pos().y()<400)
        move(0,10);
    }
    else if(event->key() == Qt::Key_1)
    {
        setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_1.png"));//sets player to sword + shield

    }
    else if(event->key() == Qt::Key_2)
    {
        setPixmap(QPixmap(":/Bow_Player_images/Player_weapon_2.png"));//sets player to bow and arrow
        ;
    }

    else if(event->key()== Qt::Key_Space){
        if(true){ //if player has bow
            Bow->play();
            newarrow = new Arrow();
            scene()->addItem(newarrow);
            /* TODO :fire arrows in speific direction   */
        }

       else{ //if player has sword+sheid
            Sword->play();
           /* TODO :figure out how to attack enemies
             with sword and shield */
       }

    }
}

void Player::move(int newX, int newY){//method adds a pixel distance to player
    setPos(x()+newX,y()+newY);
    walk->play();

qDebug() << pos().x() << pos().y();


   if(pos().y()< 50 && pos().x()> -40 &&pos().x()< 40){
                qDebug() << "go to next room";}
   if(pos().y()> 390 && pos().x()> -60 &&pos().x()< 60)
                qDebug() << "go to next room";
   if(pos().x()< -220 && pos().y()> 130 &&pos().x()< 270)
                qDebug() << "go to next room";
   if(pos().x()> 230 && pos().y()> 120 &&pos().x()< 290)
       qDebug() << "go to next room";

}

int Player::getxPos()
{
    return this->pos().x();
}

int Player::getyPos()
{
    return this->pos().y();
}



