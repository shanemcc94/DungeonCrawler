#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash ->setPixmap(QPixmap(":/images /splash.jpg"));
    splash->show();

    MainWindow w;
    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500,&w,SLOT(show()));
   //w.show();




    return a.exec();
}

/*TODO:

        Make an enemy class

        make an item class

        make a coin class (optional? -- might do some scoring stuff )

        make a door class

        make a map class

        make a room class

        make an arrow class*/
