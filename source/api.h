#ifndef API_H
#define API_H

#include <time.h>
#include <stdbool.h>

typedef enum
{
    BLACK, RED,
    GREEN, BLUE, WHITE
} color;

typedef enum
{
     KEY_W = 119, KEY_UP =    72,
     KEY_S = 115, KEY_DOWN =  80,
     KEY_A =  97, KEY_LEFT =  75,
     KEY_D = 100, KEY_RIGHT = 77,
    KEY_ESC = 27, KEY_ENTER = 13
} keybutton;

void delay(time_t d);
void setcolor(color c);
void gotoxy(int x, int y);
void clear_screen();
keybutton getkey();
bool keyhit();

#endif // API_H
