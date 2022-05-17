#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h>
#include <unistd.h>
 
int main()
{
    int ch, row, col, ypos, xpos, i;
    chtype dot = '*';
    float grav = 0.25;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, row, col);
    ypos = 0;
    xpos = (col-1)/2;
    mvaddch(ypos, xpos, dot);

    for (i = 0; ypos < row-1; i++){
        usleep(50000);
        mvdelch(ypos, xpos);
        ypos += i*grav;
        mvaddch(ypos, xpos, dot);
        refresh();
    }
    mvaddch(row-1, xpos, dot);
    refresh();
    getch();
    endwin();
    return 0;
}