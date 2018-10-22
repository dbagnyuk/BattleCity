#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "definitions.h"
#include "inclusions.h"

#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    bool GameStartTrigger = false; // trigger variable for checking if game start
//    class Player * PlayerTank = new class Player(); // create the object Player Tank

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPainter *painterMainWindow;

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_actionPlay_triggered(); // action for Play button in window menu
    void on_actionExit_triggered(); // action for Exit button in window menu

    void CreateThePlayerObject();   // in this procedure creates the player tank object and showed it's
};

#endif // MAINWINDOW_H
