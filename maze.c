#include<curses.h>
#include<locale.h>
#include<stdlib.h>
#define player "⍾"	// replacing player with ⍾
int mx,my;			// number of rows and columns of maze
char **maz;			// pointer to character array storing maze 

/*******
reads the maze from the file maze.txt into maz
*******/
void readmaze()
{
	FILE *mazep;						// creating file pointer 
	mazep=fopen("maze.txt","r");		// opning file in read mode
	fscanf(mazep,"%d %d\n",&mx,&my);	// read no. of rows and columns from file
	maz=malloc(mx*sizeof(char*));		// allocating space for row pointers
	for(int i=0;i<mx;i++)				// for each row: 
        maz[i]=malloc(my*sizeof(char));	// allocate space for row		
	for(int i=0;i<mx;i++)				// for each row:
	{
		fgets(maz[i],my,mazep);			// reads row into maz[i]
		fgetc(mazep);					// reads newline character
	}
}

/*******
displays maze and player character
*******/
void printmaze()
{
	move(0,0);								// move the cursor to (0,0)
	int flag=1;								// used to alternate bright/dark characters of maze
	for(int i=0;i<mx;i++)					// for each row:
	{
		for(int j=0;j<my;j++)				// for each element in row:
		{
			if(maz[i][j]=='X')				// if wall:
			{
				attron(COLOR_PAIR(4));		// eanble color pair 4
				printw(flag?"█":"▒");		// print alternating maze block
				attroff(COLOR_PAIR(4));		// disable color pair 4
			}
			else							// if not wall:
			{
				if(maz[i][j]=='A')			// if player:
				{							// print player character
					attron(COLOR_PAIR(2));
					printw(player);
					attroff(COLOR_PAIR(2));
				}
				else						// if any other character:
					printw("%c",maz[i][j]);	// print character
			}
			flag=!flag;						// toggle bring/dark for next block
		}
		printw("\n");						// end of row
	}
}
void up()
{
	for(int i=1;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			if(maz[i][j]=='A')
			{
				if(maz[i-1][j]!='X')
				{
					maz[i-1][j]='A';
					maz[i][j]=' ';
					printmaze();
					return;
				}
			}
		}
	}
}

void down()
{
	for(int i=0;i<mx-1;i++)
	{
		for(int j=0;j<my;j++)
		{
			if(maz[i][j]=='A')
			{
				if(maz[i+1][j]!='X')
				{
					maz[i+1][j]='A';
					maz[i][j]=' ';
					printmaze();
					return;
				}
			}
		}
	}
}
void right()
{
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my-1;j++)
		{
			if(maz[i][j]=='A')
			{
				if(maz[i][j+1]!='X')
				{
					maz[i][j+1]='A';
					maz[i][j]=' ';
					printmaze();
					return;
				}
			}
		}
	}
}
void left()
{
	for(int i=0;i<mx;i++)
	{
		for(int j=1;j<my;j++)
		{
			if(maz[i][j]=='A')
			{
				if(maz[i][j-1]!='X')
				{
					maz[i][j-1]='A';
					maz[i][j]=' ';
					printmaze();
					return;
				}
			}
		}
	}
}

int main()
{
	readmaze();
	int i,x,row,col;
	void (*move[])()={up,down,right,left};
	char c;											// input buffer
	setlocale(LC_ALL, "");							// required for rendering wide characters
	initscr();										// initialise ncurses screen
	start_color();									// initialise colors
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK); 
	noecho();										// disable echo on input
	char arr[4][4]={"↑","↓","→","←"};				// array of directional characters
	printmaze();
	while(c!='q')									// continuously read input
	{
		c = getch();								// read a byte
		getmaxyx(stdscr,row,col);					// get dimensions of terminal
		if(c==0x1b)									// if start of special character sequence:
		{
			getch();								// drop next char from buffer
			x=getch()%0x41;							// read last byte from buffer
			attron(COLOR_PAIR(x+1));
			mvprintw(row/2,col/2,arr[x]);			// print corresponding arrow at centre
			attroff(COLOR_PAIR(x+1));
			(*move[x])();							// call corresponding move function
		}
		else
			mvprintw(row/2,col/2,"%c",c);			// print any other character entered
	}
	endwin();										// restore terminal
	return 0;
}