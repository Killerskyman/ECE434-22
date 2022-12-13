#include <iostream>
#include <ncurses.h>

int main() {

    initscr();
    wclear(stdscr);
    leaveok(stdscr, true);
    nodelay(stdscr, false);
    noecho();
    keypad(stdscr, true);
    cbreak();

    int curX = 0;
    int curY = 0;
    int input;

    printf("%i by %i\n", COLS, LINES);

    while(true){
        input = wgetch(stdscr);
        switch(input){
            case KEY_UP:
                curY--;
                break;
            case KEY_DOWN:
                curY++;
                break;
            case KEY_LEFT:
                curX--;
                break;
            case KEY_RIGHT:
                curX++;
                break;
            case 100:
                clear();
                break;
            case 120:
                goto exitapp;
            default:
                break;
        }

        curX = curX >= COLS ? COLS-1 : curX;
        curX = curX <= 0 ? 0 : curX;
        curY = curY >= LINES ? LINES-1 : curY;
        curY = curY <= 0 ? 0 : curY;

        wmove(stdscr, curY, curX);
        waddstr(stdscr, "#");
        wrefresh(stdscr);
    }

exitapp:
    endwin();

    return EXIT_SUCCESS;
}
