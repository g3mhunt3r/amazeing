#include<curses.h>
#include<locale.h>
#include<stdlib.h>
int mx,my;
char **maz;
void readmaze()
{
	FILE *mazep;
	mazep=fopen("maze.txt","r");
	fscanf(mazep,"%d %d\n",&mx,&my);
	maz=malloc(mx*sizeof(char*));
	for(int i=0;i<mx;i++)
        maz[i]=malloc(my*sizeof(char));
	for(int i=0;i<mx;i++)
	{
		fgets(maz[i],my,mazep);
		fgetc(mazep);
	}
}
void printmaze()
{
	int flag=1;
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			if(maz[i][j]=='X')
			{
				attron(COLOR_PAIR(3));
				printw(flag?"█":"▒");
				attroff(COLOR_PAIR(3));
			}
			else
				printw("%c",maz[i][j]);
			flag=!flag;
		}
		printw("\n");
	}
}
int main()
{
	readmaze();
	int i,x,row,col;
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
	printmaze();
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
	endwin();
	return 0;
}