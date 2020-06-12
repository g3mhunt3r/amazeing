#include<curses.h>
int main ()
{
	int i;
	char c;
	initscr();
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
						printf("↑");
						break;
					case 0x42:
						printf("↓");
						break;
					case 0x43:
						printf("→");
						break;
					case 0x44:
						printf("←");
						break;
					default:
						printf(".");
				}
			}
		}
		//printf("\nChar: %x",c);
		fflush(stdout);
	}
	endwin();
	return 0;
}
