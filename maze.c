#include<curses.h>
#include<locale.h>
int main ()
{
	int i,x;
	char c;
	setlocale(LC_ALL, "");
	initscr();
	start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_CYAN, COLOR_BLACK);
	noecho();
	char arr[4][4]={"↑","↓","→","←"};
	while(c!='q')
	{
		c = getch();
		if(c==0x1b)
		{
			getch();
			x=getch()%0x41;
			attron(COLOR_PAIR(x+1));
			mvprintw(10,10,arr[x]);
			attroff(COLOR_PAIR(x+1));
		}
		else
			mvprintw(10,10,"%c",c);
		refresh();
	}
	endwin();
	return 0;
}