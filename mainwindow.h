#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "room.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void goToNextRoom();
    void keyPressEvent(QKeyEvent * event);
    QGraphicsScene * scene;
private slots:



private:
    Ui::MainWindow *ui;


    Player * player1;


    void CreateRoom(int R, int L, int T, int B);
};

#endif // MAINWINDOW_H
