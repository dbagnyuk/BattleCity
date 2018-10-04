#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "player.h"

class Player;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QSize MainWindowSize = this->size();

    if (!GameStartTrigger)
    {
        QPixmap StartupCover("resources\\back_800-600.jpg");
        painter.drawPixmap(0, 0,
                           StartupCover.width(), StartupCover.height() - MENUHEIGHT + MARGIN * 2, StartupCover);
    }
    else
    {
        painter.setBrush(Qt::black);
        painter.drawRect(0, 0,
                         MainWindowSize.width(), MainWindowSize.height() - MENUHEIGHT + MARGIN * 2);

        qDebug() << "--> game is started";

        class Player * PlayerTank = new class Player();

        PlayerTank->PlayerDrow(painter,PlayerTank->m_PlayerDirection,PlayerTank->PlayerCurrentPositionX,PlayerTank->PlayerCurrentPositionY);

        PlayerTank->repaint();
//        PlayerTank->setFocusPolicy(Qt::StrongFocus);
//        PlayerTank->setFocus();
//        PlayerTank->grabKeyboard();
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionPlay_triggered()
{
    qDebug() << "--> button start is pressed";

    GameStartTrigger = true;
    ui->actionPlay->setDisabled(true);
}

//void MainWindow::keyPressEvent(QKeyEvent * event)
//{
//        qDebug() << "--> start pressing keybord";
//}
