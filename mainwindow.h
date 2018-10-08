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

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;

    bool GameStartTrigger = false; // trigger variable for checking if game start

    class Player * PlayerTank = new class Player(); // create the object Player Tank

private slots:
    void on_actionPlay_triggered(); // action for Play button in window menu
    void on_actionExit_triggered(); // action for Exit button in window menu
    void RepaintAfterKeyPress();    // I think this method I can use from the Player class for update after arrow pressed
};

#endif // MAINWINDOW_H
