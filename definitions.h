#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define PlayerImagesCount 4 //4 pix for Player Tank
#define EnemyImagesCount 4  //4 pix for Enemy Tank
#define BulletImagesCount 4 //4 pix of 4 directions for bullet

#define MENUHEIGHT 25       // window menu height in pixels
#define MARGIN 5            // window border size in pixels
#define PLAYERSPEED 10      // how many pixels in player's step
#define ENEMYSPEED 10       // how many pixels in enemy's step
#define BULLETSPEED 50      // how many pixels in bullet step

enum Direction{Up, Right, Down, Left, Space}; // enum for directions, used for all muvement objects
enum PlayerId {Player,Enm = 4};               // I'm don't remember is for what I create this

#define MainWindowSizeWidth 800               // width of game window in pixels
#define MainWindowSizeHeight 600              // height of game window in pixels


#endif // DEFINITIONS_H
