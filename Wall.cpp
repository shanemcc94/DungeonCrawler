#include "wall.h"



/*TODO: make a room class that can generate a
 *      combination of walls and doors based
 *      on inputs to be able to build map

        make a door class that allows you to
        travel between rooms

        make some colloistion detection*/


Wall::Wall(int code): QGraphicsPixmapItem()
{
    if(code%2){
        door = true;
    }
    else{
        door = false;
    }

    switch (code) {
    case 1: //rightwall
                setPixmap(QPixmap(":/images /bg_side_wall.png"));
                setPos(x()+274,y());
        break;
    case 2: //rightdoor
                setPixmap(QPixmap(":/images /bg_side_door.png"));
                setPos(x()+230,y());
        break;
    case 3: //leftwall
                setPixmap(QPixmap(":/images /bg_side_wall.png"));
                setPos(x()-274,y());
                setTransformOriginPoint(25,248);
                setRotation(180);
        break;
    case 4: //leftdoor
                setPixmap(QPixmap(":/images /bg_side_door.png"));
                setPos(x()-230,y());
                setTransformOriginPoint(25,248);
                setRotation(180);
        break;
    case 5: //topwall
                setPixmap(QPixmap(":/images /bg_End_wall.png"));
                setPos(x()-274,y());
        break;
    case 6: //topdoor
                setPixmap(QPixmap(":/images /bg_End_Door.png"));
                setPos(x()-274,y());
        break;
    case 7: //bottomwall
                setPixmap(QPixmap(":/images /bg_End_wall.png"));
                setPos(x()+274,y());
                setTransformOriginPoint(25,248);
                setRotation(180);
        break;
    case 8: //bottomdoor
                setPixmap(QPixmap(":/images /bg_End_Door.png"));
                setPos(x()+274,y());
                setTransformOriginPoint(25,248);
                setRotation(180);
        break;
    default:
        break;
    }

}


//NOTE: may not need these classes in future
bool Wall::isDoor()
{
    return this->door;
}

void Wall::setSide(bool side)
{
    setPixmap(QPixmap(":/images /bg_side_wall.png"));
    if(side){
        //rightsdie wall

       setPos(x()+274,y());
    }
    else{
        //leftside wall
        setPos(x()-274,y());
        setTransformOriginPoint(25,248);
        setRotation(180);
       // setRotation(180);
    }
}
void Wall::setEnd(bool end)
{
    setPixmap(QPixmap(":/images /bg_End_wall.png"));
    if(end){
        //Top wall

       setPos(x()-274,y());
    }
    else{
        //Bottom wall
        setPos(x()-274,y()+460);
        setTransformOriginPoint(300,25);
        setRotation(180);
       // setRotation(180);
    }
}
