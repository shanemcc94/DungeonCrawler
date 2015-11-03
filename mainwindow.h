#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QKeyEvent>


namespace Ui {
class MainWindow;
}

class MainWindow :public QMainWindow{


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    Player * player1;
    QGraphicsScene * scene;

private slots:

    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    



};

#endif // MAINWINDOW_H
