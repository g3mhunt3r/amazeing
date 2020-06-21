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
			if(getch()==0x5b)
			{
				switch(getch())
				{
					case 0x41:
						attron(COLOR_PAIR(1));
						printw("↑");
						attroff(COLOR_PAIR(1));
						break;
					case 0x42:
						attron(COLOR_PAIR(2));
						printw("↓");
						attroff(COLOR_PAIR(2));
						break;
					case 0x43:
						attron(COLOR_PAIR(3));
						printw("→");
						attroff(COLOR_PAIR(3));
						break;
					case 0x44:
						attron(COLOR_PAIR(4));
						printw("←");
						attroff(COLOR_PAIR(4));
						break;
					default:
						printw(".");
				}
			}
		}
		else
			printw("%c",c);
		printw("\n");
		refresh();
	}
	endwin();
	return 0;
}
