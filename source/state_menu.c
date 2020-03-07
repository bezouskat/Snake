#include "state_menu.h"

#include <stdio.h>
#include "api.h"
#include "constants.h"
#include "settings.h"

void draw_menu_frame()
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

void draw_menu_title()
{
    setcolor(GREEN);

    gotoxy(10, 2); printf("       _______..__   __.      ___       __  ___  _______   ");
    gotoxy(10, 3); printf("      /       ||  \\ |  |     /   \\     |  |/  / |   ____|  ");
    gotoxy(10, 4); printf("     |   (----`|   \\|  |    /  ^  \\    |  '  /  |  |__     ");
    gotoxy(10, 5); printf("      \\   \\    |  . `  |   /  /_\\  \\   |    <   |   __|    ");
    gotoxy(10, 6); printf("  .----)   |   |  |\\   |  /  _____  \\  |  .  \\  |  |____   ");
    gotoxy(10, 7); printf("  |_______/    |__| \\__| /__/     \\__\\ |__|\\__\\ |_______|  ");
}

void menu_items()
{
    setcolor(WHITE);

    gotoxy(35, 11); printf("New Game");
    gotoxy(35, 13); printf("Settings");
    gotoxy(35, 15); printf("Quit Game");
}

void state_menu()
{
    int item = 11;

    clear_screen();
    draw_menu_frame();
    draw_menu_title();
    menu_items();

    gotoxy(31, item);
    printf("-->");

    gotoxy(3, 22);
    printf("Press <RETURN> to select an item...");

    while (true)
    {
        if (keyhit())
        {
            keybutton key = getkey();

            if (key == KEY_UP || key == KEY_W)
            {
                if (item >= 13)
                {
                    gotoxy(31, item);
                    printf("   ");
                    item -= 2;
                    gotoxy(31, item);
                    printf("-->");
                }
            }
            else if (key == KEY_DOWN || key == KEY_S)
            {
                if (item <= 13)
                {
                    gotoxy(31, item);
                    printf("   ");
                    item += 2;
                    gotoxy(31, item);
                    printf("-->");
                }
            }
            else if (key == KEY_ENTER)
            {
                switch (item)
                {
                    case 11: settings.current_state = PLAY; return;
                    case 13: settings.current_state = SETTINGS; return;
                    case 15: settings.running = false; return;
                }
            }

            gotoxy(38, 22);
        }
    }
}
