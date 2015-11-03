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


    Wall * RightSide = new Wall();
    RightSide->setSide(true);
    Wall * LeftSide = new Wall();
    LeftSide->setSide(false);
    Wall * TopSide = new Wall();
    TopSide->setEnd(true);
    Wall * BottomSide = new Wall();
    BottomSide->setEnd(false);

    scene->addItem(player1);


    scene->addItem(enemy3);
    scene->addItem(enemy4);
    scene->addItem(enemy5);
    scene->addItem(RightSide);
    scene->addItem(LeftSide);
    scene->addItem(TopSide);
    scene->addItem(BottomSide);
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

