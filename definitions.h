#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define PlayerImagesCount 8 //4 pix for Player Tank + 4 for Enemy Tank
#define bulletImagesCount 4 //4 pix of 4 directions for bullet

#define MENUHEIGHT 21
#define MARGIN 10
#define PLAYERSPEED 10
#define ENEMYSPEED 10
#define BULLETSPEED 25

enum Direction{Right, Left, Down, Up, Space};
enum PlayerId {Player,Enm = 4};

#endif // DEFINITIONS_H
