#include <QApplication>

#include "definitions.h"
#include "inclusions.h"

#include "mainwindow.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


//    class Player * PlayerTank = new class Player();

//    PlayerTank.setFocusPolicy(Qt::StrongFocus);
//    PlayerTank->setFocus();

    return a.exec();
}
