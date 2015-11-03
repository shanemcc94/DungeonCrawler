#ifndef WALL
#define WALL

#include <QGraphicsPixmapItem>

class Wall: public QGraphicsPixmapItem{
private:
    bool door;

public:
    Wall(int code);
    bool isDoor();
    void setSide(bool side);
    void setEnd(bool end);
};

#endif // SIDEWALL

