
#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h> 
 
int main()
{
    int ch, row, col, ypos, xpos;
    chtype cursor = '*';

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, row, col);
    ypos = row/2;
    xpos = (col-1)/2;
    mvaddch(ypos, xpos, cursor);

    while((ch = getch()) != KEY_F(1)){
        switch(ch)
        {
            case KEY_LEFT:
                mvdelch(ypos, xpos);
                xpos--;
                break;
            case KEY_RIGHT:
                mvdelch(ypos, xpos);
                xpos++;
                break;
            case KEY_DOWN:
                mvdelch(ypos, xpos);
                ypos++;
                break;
            case KEY_UP:
                mvdelch(ypos, xpos);
                ypos--;
                break;
            default:
                break;
        }
        mvaddch(ypos, xpos, cursor);
        refresh();
    }
    endwin();
    return 0;
}