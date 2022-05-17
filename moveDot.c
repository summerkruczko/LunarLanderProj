#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h> 
 
int main()
{
    int ch, row, col, ypos, xpos;
    chtype dot = '*';

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, row, col);
    ypos = row/2;
    xpos = (col-1)/2;
    mvaddch(ypos, xpos, dot);

    while((ch = getch()) != KEY_F(1)){
        switch(ch)
        {
            case KEY_LEFT:
                mvdelch(ypos, xpos);
                if (xpos != 0) xpos--;
                break;
            case KEY_RIGHT:
                mvdelch(ypos, xpos);
                if (xpos != col-1) xpos++;
                break;
            case KEY_DOWN:
                mvdelch(ypos, xpos);
                if (ypos != row-1) ypos++;
                break;
            case KEY_UP:
                mvdelch(ypos, xpos);
                if (ypos != 0) ypos--;
                break;
            default:
                break;
        }
        mvaddch(ypos, xpos, dot);
        refresh();
    }
    endwin();
    return 0;
}