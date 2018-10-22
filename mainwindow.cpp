#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // focus the game window
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();

    painterMainWindow = new QPainter(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // create painter object
//    QPainter painter(this);
    QSize MainWindowSize = this->size();
    painterMainWindow->begin(this);

    // condition for start game
    if (!GameStartTrigger)
    {
        // if game is not started (when it's opened) we drow black background and the picture with Battle City logo
        QPixmap StartupCover("resources\\back_800-600.jpg");
        painterMainWindow->drawPixmap(0, 0 + MENUHEIGHT - MARGIN,
                           StartupCover.width(), StartupCover.height(), StartupCover);
    }
    else
    {
        // if game was start then drow a black back ground
        painterMainWindow->setBrush(Qt::black);
        painterMainWindow->drawRect(0, 0 + MENUHEIGHT - MARGIN,
                         MainWindowSize.width(), MainWindowSize.height());

//        qDebug() << "--> game is started";

        // drow the player's tank
//        PlayerTank->PlayerDrow(painter);

        // update the paintEvent. It's updated constantly!!! maybe it's not a good idea,
        // maybe it should update after the button pressed, but now I don't know how to do this
        // I should think about it!
        this->update();
    }
    painterMainWindow->end();
}

// action for Exit button in window menu
void MainWindow::on_actionExit_triggered()
{
    // when the button Exit is pressed, the window is close
    close();
}

// action for Play button in window menu
void MainWindow::on_actionPlay_triggered()
{
    qDebug() << "--> button start is pressed";

    GameStartTrigger = true; // trigger variable for checking if game start
    ui->actionPlay->setDisabled(true); // when the Play button pressed it go to disable mode

    CreateThePlayerObject();
}

// in this procedure creates the player tank object and showed it's
void MainWindow::CreateThePlayerObject()
{
   class Player * PlayerTank = new class Player(); // create the object Player Tank
   PlayerTank->show();
}

// destructor for close the game window
MainWindow::~MainWindow()
{
    delete ui;
}
