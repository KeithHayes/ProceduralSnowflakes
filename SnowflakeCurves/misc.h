#ifndef MISC_H
#define MISC_H

#define LEVEL_DEFAULT 3
#define INITIATOR_DEFAULT 4
#define SCALE_DEFAULT 1
#define LEVEL_MAX 10
#define INITIATOR_MAX 20
#define SCALE_MAX 2

#define RAND_INITIAL_SEED 3030303L
#define RAND_TABLE_SIZE 128
#define MINSIZE(A,B) (((A) > (B)) ? (B) : (A))

#define KOCH {Point(0,0),Point(1,0),Point(1.5,0.866025404),Point(2.0,0),Point(3,0)}
#define SQUARE {Point(0,0),Point(1,0),Point(1,1),Point(2,1),Point(2,0),Point(2,-1),Point(3,-1),Point(3,0),Point(4,0)}
#define PEANO {Point(0,0),Point(1,0),Point(1,1),Point(2,1),Point(2,0),Point(1,0),Point(1,-1),Point(2,-1),Point(2,0),Point(3,0)}
#define POLY_TEXT "     (0, 0), (1, 0), (1, 1), (2, 1), (2, 0), (3, 0)"

#define PI_OVER2 1.570796327
#define PI 3.141592654
#define TWO_PI (6.283185308)
#define RADIANS_TO_DEGREES 57.29577951
#define DEGREES_TO_RADIANS 0.01745329252
#define SQRT_TWO 1.41421356237

#define VK_MIN(A,B) (((A) > (B)) ? (B) : (A))
#define VK_MAX(A,B) (((A) < (B)) ? (B) : (A))

#define BLACK  "#000000"
#define BLUE   "#0000aa"
#define GREEN  "#00aa00"
#define TEAL   "#00aaaa"
#define DKGREY "#555555"
#define VIOLET "#5555ff"
#define LIME   "#55ff55"
#define AQUA   "#55ffff"
#define DKRED  "#aa0000"
#define PLUM   "#aa00aa"
#define BROWN  "#aa5500"
#define LTGREY "#aaaaaa"
#define ORANGE "#ff5555"
#define PINK   "#ff55ff"
#define YELLOW "#ffff55"
#define WHITE  "#ffffff"
#define GOLD   "#FAD200"

#define COLORS { "#000000","#0000aa","#00aaaa","#555555", \
                 "#5555ff","#55ff55","#55ffff","#aa0000", \
                 "#aa00aa","#aa5500","#aaaaaa","#ff5555", \
                 "#ff55ff","#ffff55","#ffffff","#FAD200" }

#endif
