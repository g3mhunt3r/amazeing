#include<curses.h>
#include<locale.h>
int main ()
{
	int i;
	char c;
	setlocale(LC_ALL, "");
	initscr();
	start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_CYAN, COLOR_BLACK);
	noecho();
	while(c!='q')
	{
		c = getch();
		if(c==0x1b)
		{	
			getch();
			switch(getch())
			{
				case 0x41:
					attron(COLOR_PAIR(1));
					mvprintw(10,10,"↑");
					attroff(COLOR_PAIR(1));
					break;
				case 0x42:
					attron(COLOR_PAIR(2));
					mvprintw(10,10,"↓");
					attroff(COLOR_PAIR(2));
					break;
				case 0x43:
					attron(COLOR_PAIR(3));
					mvprintw(10,10,"→");
					attroff(COLOR_PAIR(3));
					break;
				case 0x44:
					attron(COLOR_PAIR(4));
					mvprintw(10,10,"←");
					attroff(COLOR_PAIR(4));
					break;
				default:
					mvprintw(10,10,".");
			}
		}
		else
			mvprintw(10,10,"%c",c);
		refresh();
	}
	endwin();
	return 0;
}
