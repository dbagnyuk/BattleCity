#ifndef BULLET_H
#define BULLET_H

#include "definitions.h"
#include "inclusions.h"

#include "mainwindow.h"
#include "player.h"

class Bullet: public QObject
{
    Q_OBJECT

//    BulletId m_Id;
    static QPixmap * m_BulletArray;

public:
    static int BulletWidth, BulletHeight; // mesure of Bullet object
    static int BulletCurrentPositionX, BulletCurrentPositionY; // position of the Bullet wich will be change
    static Direction BulletDirection; // Bullet direction
//    static QPainter painter_;


public:
    explicit Bullet();
    ~Bullet();
    static void BulletLoadBitmaps(); // load the pictures of bullet in memory
    static void BulletWidthHeightInit(); // init the width and height of the Bullet object

//    void BulletDrow(/*QPainter &painter*/); // procedure for drow the Bullet
    static void BulletDrow(QPainter &painter); // procedure for drow the Bullet

private:
//    QPainter painter_;

private slots:
    void on_bulletMove(); // timer which restart the procedure of fly bullet
    void on_bulletMove_triggered(); // trigger for bullet fly until death
};
#endif // BULLET_H
