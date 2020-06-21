#include<curses.h>
#include<locale.h>
void readmaze()
{
	int x,y;
	FILE *mazep;
	mazep=fopen("maze.txt","r");
	fscanf(mazep,"%d %d\n",&x,&y);
	char maz[x][y];
	for(int i=0;i<x;i++)
	{
		fgets(maz[i],y,mazep);
		fgetc(mazep);
		printf("%s\n",maz[i]);
	}
	/*or(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			printf("%c",maz[i][j]);
		}
		printf("\n%d\n",i);
	}*/
}
int main()
{
	readmaze();
	/*int i,x,row,col;
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
		clear();
		getmaxyx(stdscr,row,col);
		if(c==0x1b)
		{
			getch();
			x=getch()%0x41;
			attron(COLOR_PAIR(x+1));
			mvprintw(row/2,col/2,arr[x]);
			attroff(COLOR_PAIR(x+1));
		}
		else
			mvprintw(row/2,col/2,"%c",c);
		refresh();
	}
	endwin();*/
	return 0;
}