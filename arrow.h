#ifndef ARROW
#define ARROW
#include <QObject>
#include <QGraphicsRectItem>




class Arrow:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT//MACRO
public:

    Arrow();
public slots:
    void move();

};

#endif // ARROW

