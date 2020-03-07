#include "api.h"

#include <conio.h>
#include <windows.h>

void delay(time_t d)
{
    clock_t time;

    time = clock() + d;
    while (clock() < time) {}
}

void setcolor(color c)
{
    switch (c)
    {
        case BLACK: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);  break;
        case RED: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                          FOREGROUND_INTENSITY | FOREGROUND_RED);   break;
        case GREEN: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                          FOREGROUND_INTENSITY | FOREGROUND_GREEN); break;
        case BLUE: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                          FOREGROUND_INTENSITY | FOREGROUND_BLUE);  break;
        case WHITE: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);  break;
    }
}

void gotoxy(int x, int y)
{
    COORD point;

    point.X = x;
    point.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void clear_screen()
{
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
}

keybutton getkey()
{
    int key = getch();

    if (key == 0 || key == 0xE0)
      key = getch();

    return key;
}

bool keyhit()
{
    return kbhit();
}
