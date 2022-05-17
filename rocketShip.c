#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h>
#include <unistd.h>
 
int main()
{
    int ch, row, col, ypos, xpos, fallTime = 0, thrustTime = 0;
    chtype ship = '*';
    float grav = 0.25, thrust = 0.5;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, row, col);
    ypos = 5;
    xpos = (col-1)/2;
    mvaddch(ypos, xpos, ship);

    while((ch = getch()) != KEY_F(1)){
        while(ypos != col-1){
            
        }
        mvaddch(row-1, xpos, ship);
        refresh();  
    }
    
    endwin();
    return 0;
}

/* to pilfer
for (i = 0; ypos < row-1; i++){
            usleep(50000);
            mvdelch(ypos, xpos);
            ypos += i*grav;
            mvaddch(ypos, xpos, ship);
            refresh();
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
                case KEY_UP:
                    mvdelch(ypos, xpos);
                    if (ypos != 0) ypos--;
                    break;
                default:
                    break;
            }
        }
*/
        