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

    return a.exec();
}
