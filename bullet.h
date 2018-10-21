#ifndef BULLET_H
#define BULLET_H

#include "definitions.h"
#include "inclusions.h"

#include "mainwindow.h"
#include "player.h"

class Bullet: /*public QObject, */public QWidget
{
    Q_OBJECT

//    BulletId m_Id;
    static QPixmap * m_BulletArray;

public:
    static int BulletWidth, BulletHeight; // mesure of Bullet object
    static int BulletCurrentPositionX, BulletCurrentPositionY; // position of the Bullet wich will be change
    static Direction BulletDirection; // Bullet direction

public:
    explicit Bullet(QWidget *parent = 0);
    ~Bullet();
    void BulletLoadBitmaps(); // load the pictures of bullet in memory
    void BulletWidthHeightInit(); // init the width and height of the Bullet object

//    void BulletDrow(/*QPainter &painter*/); // procedure for drow the Bullet
//    void BulletDrow(QPainter &painter); // procedure for drow the Bullet

private:
    void paintEvent(QPaintEvent * event);

private slots:
    void on_bulletMove(); // timer which restart the procedure of fly bullet
    void on_bulletMove_triggered(); // trigger for bullet fly until death
};
#endif // BULLET_H
