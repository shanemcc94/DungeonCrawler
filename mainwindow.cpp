#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "arrow.h"
#include "wall.h"
#include "endwall.h"
#include "enemy.h"
#include <QBrush>
#include <QImage>
#include<QTimer>
#include <QDebug>

/* TODO: try clean up all scene declarations (maybe put into its own class/method)

         try clean up wall declaration(make room class to put everything)*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();

    Player * player1 = new Player();

    Enemy * enemy3 = new Enemy();
    Enemy * enemy4 = new Enemy();
    Enemy * enemy5 = new Enemy();


    scene->addItem(player1);

      
   


    CreateRoom(1,3,5,7);


    scene->addItem(enemy3);
    scene->addItem(enemy4);
    scene->addItem(enemy5);
    ui->graphicsView->setScene(scene);



    scene->setBackgroundBrush(QBrush(QImage(":/images /bg.png")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}




MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

}



void MainWindow::on_pushButton_4_clicked()
{

}
void MainWindow::goToNextRoom()
{
    int xpos =player1->getxPos();
    int ypos =player1->getyPos();
    if(ypos< 50 && xpos> -40 &&xpos< 40){
        qDebug() << "go to next room";}
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    goToNextRoom();
}


void MainWindow::CreateRoom(int R,int L, int T , int B)
{

    Wall * TWall = new Wall(R);
    Wall * BWall = new Wall(L);
    Wall * LWall = new Wall(T);
    Wall * RWall = new Wall(B);


    scene->addItem(TWall);
    scene->addItem(BWall);
    scene->addItem(LWall);
    scene->addItem(RWall);
}
