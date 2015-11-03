#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "arrow.h"

class Player: public QGraphicsPixmapItem, QObject
{

private:
    int playerType;

public:

    Player();
    Arrow* arrow;
    void keyPressEvent(QKeyEvent * event);
    void move(int newX, int newY);
    void setPlayerType(int NewPlayerType);
    int getPlayerType();   
    int getxPos();
    int getyPos();

/*private:
    QPixmap playerUp;
    QPixmap playerDown;
    QPixmap playerLeft;
    QPixmap playerRight;*/

};




#endif // PLAYER

