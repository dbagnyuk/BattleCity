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

    bool GameStartTrigger = false;

private slots:
    void on_actionPlay_triggered();
    void on_actionExit_triggered();
//    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
