#include "state_settings.h"

#include <stdio.h>
#include "api.h"
#include "constants.h"
#include "settings.h"

void draw_settings_frame()
{
    setcolor(RED);

    int i;

    for (i = 0; i <= SCREEN_WIDTH; ++i)
    {
        gotoxy(i, 0);
        putchar(FRAME);

        gotoxy(i, SCREEN_HEIGHT);
        putchar(FRAME);
    }

    for (i = 0; i <= SCREEN_HEIGHT; ++i)
    {
        gotoxy(0, i);
        putchar(FRAME);

        gotoxy(SCREEN_WIDTH, i);
        putchar(FRAME);
    }

    gotoxy(0, 0);
}

void draw_settings_title()
{
    setcolor(WHITE);

    gotoxy(3, 2); printf("  __      _   _   _                  ");
    gotoxy(3, 3); printf(" / _\\ ___| |_| |_(_)_ __   __ _ ___  ");
    gotoxy(3, 4); printf(" \\ \\ / _ \\ __| __| | '_ \\ / _` / __| ");
    gotoxy(3, 5); printf(" _\\ \\  __/ |_| |_| | | | | (_| \\__ \\ ");
    gotoxy(3, 6); printf(" \\__/\\___|\\__|\\__|_|_| |_|\\__, |___/ ");
    gotoxy(3, 7); printf("                          |___/      ");
}

void settings_items()
{
    setcolor(WHITE);

    gotoxy(30, 11); printf("Movement: <arrows> | <WSAD>");
    gotoxy(30, 13); printf("Pause:    <ESC>");
    gotoxy(30, 15); printf("Start Level:  %c %3d %c", 17, settings.start_level, 16);
    gotoxy(30, 17); printf("Start Length: %c %3d %c", 17, settings.start_length, 16);
}

void state_settings()
{
    int item = 15;

    clear_screen();
    draw_settings_frame();
    draw_settings_title();
    settings_items();

    gotoxy(26, item);
    printf("-->");

    gotoxy(3, 22);
    printf("Press <ESC> to return back to the menu...");

    while (true)
    {
        if (keyhit())
        {
            keybutton key = getkey();

            if (key == KEY_UP || key == KEY_W)
            {
                if (item == 17)
                {
                    gotoxy(26, item);
                    printf("   ");
                    item -= 2;
                }

                gotoxy(26, item);
                printf("-->");
            }
            else if (key == KEY_DOWN || key == KEY_S)
            {
                if (item == 15)
                {
                    gotoxy(26, item);
                    printf("   ");
                    item += 2;
                }

                gotoxy(26, item);
                printf("-->");
            }
            else if (key == KEY_LEFT || key == KEY_A)
            {
                if (item == 15)
                {
                    if (settings.start_level > 1)
                    {
                        --settings.start_level;
                        gotoxy(30, 15);
                        printf("Start Level:  %c %3d %c", 17, settings.start_level, 16);
                    }
                }
                else if (item == 17)
                {
                    if (settings.start_length > 1)
                    {
                        --settings.start_length;
                        gotoxy(30, 17);
                        printf("Start Length: %c %3d %c", 17, settings.start_length, 16);
                    }
                }
            }
            else if (key == KEY_RIGHT || key == KEY_D)
            {
                if (item == 15)
                {
                    if (settings.start_level < 10)
                    {
                        ++settings.start_level;
                        gotoxy(30, 15);
                        printf("Start Level:  %c %3d %c", 17, settings.start_level, 16);
                    }
                }
                else if (item == 17)
                {
                    if (settings.start_length < 999)
                    {
                        ++settings.start_length;
                        gotoxy(30, 17);
                        printf("Start Length: %c %3d %c", 17, settings.start_length, 16);
                    }
                }
            }
            else if (key == KEY_ESC)
            {
                settings.current_state = MENU;
                return;
            }

            gotoxy(44, 22);
        }
    }
}
