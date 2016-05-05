# xtreme_game_coder_is_here
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#define conn 4

void init(struct player p);
void push(struct player p);
void pop(struct player p);
//============================DATA STRUCTURE STACK============================

struct player
{
	int entry[conn];
	int top;
};

void init(struct player *p)
{
	p->top=0;
}


void push(struct player *p)
{
	int x=19;
	p->entry[p->top]=x;
	p->top++;
}

void pop(struct player *p)
{
	int x;
	p->top--;
	x=p->entry[p->top];
}

//============================================================================
int i,j,drad=20;
int grid[50][50],y,slots=42,count=0;
struct board
{
	int left_x_co;
	int top_y_co;
	int right_x_co;
	int bottom_y_co;
}brd;

struct disc
{
      int x_cord;
      int y_cord;
      int x_rad;
      int y_rad;
}dsc;

struct selector
{
	int old_points[8];
	int new_points[8];
}sel;

void background1()
{
	cleardevice();
	for(int i=0;i<=15;i++)
	{
		setbkcolor(0);
		setcolor(i);
		settextstyle(0,0,2);
		outtextxy(170,200,"Player 1 wins..!!");
		outtextxy(130,250,"Press 'Q' to quit..!!");
		delay(50);
		if(i==15)
			i=1;
		if(inportb(0x60)==16)
			exit(0);
	}
}

void background2()
{
	cleardevice();
	for(int i=0;i<=15;i++)
	{
		setbkcolor(0);
		setcolor(i);
		settextstyle(0,0,2);
		outtextxy(170,200,"Player 2 wins..!!");
		outtextxy(130,250,"Press 'Q' to quit..!!");
		delay(50);
		if(i==15)
			i=1;
		if(inportb(0x60)==16)
			exit(0);
	}
}

void background4()
{
	cleardevice();
	for(int i=0;i<=15;i++)
	{
		setbkcolor(0);
		setcolor(i);
		settextstyle(0,0,2);
		outtextxy(125,200,"Oh NO..!! Its a TIE..!!");
		outtextxy(130,250,"Press 'Q' to quit..!!");
		delay(50);
		if(i==15)
			i=1;
		if(inportb(0x60)==16)
			exit(0);
	}
}

void background3()
{
	cleardevice();
	for(int i=0;i<=15;i++)
	{
		setbkcolor(0);
		setcolor(i);
		settextstyle(0,0,4);
		outtextxy(170,150,"CONNECT 4");
		settextstyle(0,0,1);
		outtextxy(180,200,"Created By : Nikhil Sunil Purohit");
		outtextxy(10,250,"Use 'A' to move the selector to the LEFT");
		outtextxy(10,280,"Use 'S' to move the selector to the RIGHT");
		outtextxy(10,310,"Press 'L' to insert the Disc into the slots");
		outtextxy(10,340,"Its a two player game so one who Connects 4, WINS..!!");
		outtextxy(10,370,"You can press 'Q' anytime in the middle of the game to QUIT..!!");
		outtextxy(10,400,"Press 'Q' to start the GAME..!! GOOD LUCK..!!");
		delay(50);
	      /*	sound(300);
		nosound();
		delay(100);
		sound(500);
		nosound();
		delay(100);
		sound(300); */

		if(i==15)
			i=1;
		if(inportb(0x60)==16)
			break;
	}
	delay(500);
}


void winner(int win)
{
	settextstyle(4,0,1);
	if(win==1)
	{
		delay(500);
		background1();
	}
	else if(win==2)
	{
		delay(500);
		background2();
	}
	else
	{
		delay(500);
		background4();
	}
}

void check(struct player *p)
{
	//for horizontal possibilities

	for(int i=60;i<=410;i=i+70)
	{
		for(int j=80;j<=560;j=j+80)
		{
			if(grid[i][j]==1)
			{
				push(p);
			}
			else
			{
				while(p->top!=0)
				{
					pop(p);
				}
			}
			if(p->top==conn)
			{
				winner(1);
			}

		}
	}

	//for vertical possibilities

	for(i=80;i<=560;i=i+80)
	{
		for(int j=60;j<=410;j=j+70)
		{
			if(grid[j][i]==1)
			{
				push(p);
			}
			else
			{
				while(p->top!=0)
				{
					pop(p);
				}
			}
			if(p->top==conn)
			{
				winner(1);
			}

		}
	}

	for(i=60;i<=410;i=i+70)
	{
		for(int j=80;j<=560;j=j+80)
		{
			if(grid[i][j]==2)
			{
				push(p);
			}
			else
			{
				while(p->top!=0)
				{
					pop(p);
				}
			}
			if(p->top==conn)
			{
				winner(2);
			}

		}
	}

	//for vertical possibilities

	for(i=80;i<=560;i=i+80)
	{
		for(int j=60;j<=410;j=j+70)
		{
			if(grid[j][i]==2)
			{
				push(p);
			}
			else
			{
				while(p->top!=0)
				{
					pop(p);
				}
			}
			if(p->top==conn)
			{
				winner(2);
			}

		}
	}


	//checking for crosswise possibilities
	//left-top to right bottom

       /*	for(int i=80;i<=560;i=i+80)
	{
		for(int j=60;j<=410;j=j+70)
		{
			if(grid[i][j]==1);
			{
				push();

			}
			else
			{
				while(p->top!=0)
				{
					pop();
				}
			}
			if(p->top==conn)
			{
				return(1);
			}

		}
	}*/

}

int insert(int x,int chance)
{
	int flag=0;
	delay(100);
	int y=410;
	if(chance==1)
	{
		for(y=410;y>60;y=y-70)
		{
			if(grid[y][x]==0)
			{
				flag=1;
				break;
			}
			if(flag==1)
			break;
		}
		if(grid[y][x]==2 || grid[y][x]==1)
		{
		       return(1);
		}
		else
		{
			setfillstyle(1,RED);
			fillellipse(x,y,drad,drad);
			grid[y][x]=1;
			return(2);
		}
	}
	else if(chance==2)
	{
		for(y=410;y>60;y=y-70)
		{
			if(grid[y][x]==0)
			{
				flag=1;
				break;
			}
			if(flag==1)
			break;
		}
		if(grid[y][x]==2 || grid[y][x]==1)
		{
			return(2);
		}
		else
		{
			setfillstyle(1,YELLOW);
			fillellipse(x,y,drad,drad);
			grid[y][x]=2;
			return(1);
		}
	}

}
int moveselector(char ch)
{
	int n=8;
	switch(ch)
	{
		case 'A':
			if(sel.new_points[0]>80)
			{
				for(int k=0;k<n;k++)
				{
					sel.old_points[k]=sel.new_points[k];
				}
				for(k=0;k<n;k++)
				{
					if(k%2==0)
					{
						sel.new_points[k]=sel.new_points[k]-80;
					}
				}

				//Remove old selector

				setcolor(0);
				setfillstyle(1,0);
				drawpoly(8,sel.old_points);
				fillpoly(8,sel.old_points);

				//draw new selector
				setfillstyle(1,YELLOW);
				fillpoly(8,sel.new_points);
				delay(100);
			}
			break;

		case 'S':
			if(sel.new_points[2]<580)
			{
				for(int k=0;k<n;k++)
				{
					sel.old_points[k]=sel.new_points[k];
				}
				for(k=0;k<n;k++)
				{
					if(k%2==0)
					{
						sel.new_points[k]=sel.new_points[k]+80;
					}
				}

				//Remove old selector
				setcolor(0);
				setfillstyle(1,0);
				drawpoly(8,sel.old_points);
				fillpoly(8,sel.old_points);

				//draw new selector
				setfillstyle(1,YELLOW);
				fillpoly(8,sel.new_points);
				delay(100);

			}
			break;
	}
	return(sel.new_points[4]);
}

void play()
{
	int x,chance=1;
	struct player p;
	init(&p);
	while(inportb(0x60)!=16)
	{
		delay(100);	// REDUCING THE GAME SPPED //
		if(inportb(0x60)==30) x=moveselector('A');
		if(inportb(0x60)==31) x=moveselector('S');
		if(inportb(0x60)==38)
		{
			chance=insert(x,chance);
			check(&p);
		}
	}
}

void initialize()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c://tc//bgi");

	setbkcolor(BLACK);

	//border//

	line(5,0,5,470);
	line(5,0,635,0);
	line(635,0,635,470);
	line(5,470,635,470);

	//initializing the board

	brd.left_x_co=40;
	brd.top_y_co=25;
	brd.right_x_co=600;
	brd.bottom_y_co=445;

	//initializing the selector

	sel.new_points[0]=300;
	sel.new_points[1]=10;
	sel.new_points[2]=340;
	sel.new_points[3]=10;
	sel.new_points[4]=320;
	sel.new_points[5]=20;
	sel.new_points[6]=300;
	sel.new_points[7]=10;
	setfillstyle(1,YELLOW);
	fillpoly(4,sel.new_points);
}

void drawboard()
{
	//drawing the board at initial state

	setfillstyle(7,BLUE);
	bar(brd.left_x_co,brd.top_y_co,brd.right_x_co,brd.bottom_y_co);

	//drawing the coloumns

	line(40,25,40,445);
	line(120,25,120,445);
	line(200,25,200,445);
	line(280,25,280,445);
	line(360,25,360,445);
	line(440,25,440,445);
	line(520,25,520,445);
	line(600,25,600,445);

	//drawing the rows

	line(40,25,600,25);
	line(40,95,600,95);
	line(40,165,600,165);
	line(40,235,600,235);
	line(40,305,600,305);
	line(40,375,600,375);
	line(40,445,600,445);

	for(int i=410;i>=60;i=i-70)
	{
		for(int j=80;j<=560;j=j+80)
		{
			setfillstyle(1,0);
			fillellipse(j,i,20,20);
			grid[i][j]=0;
		}
	}

	settextstyle(0,1,2);
	outtextxy(32,80,"Player ONE is RED");
	outtextxy(622,55,"Player TWO is YELLOW");
	settextstyle(0,0,2);
	outtextxy(70,450,"********** CONNECT 4 **********");
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c://tc//bgi");

	initialize();
	background3();
	cleardevice();
	drawboard();
	play();
	getch();
	closegraph();
}
