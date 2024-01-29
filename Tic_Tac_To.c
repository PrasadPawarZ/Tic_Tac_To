#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>


int data[10]={0,0,0,0,0,0,0,0,0,0};
char square[10]={'0','1','2','3','4','5','6','7','8','9'};



void board()
{
	clrscr();
	setcolor(WHITE);
	setbkcolor(BLACK);
	setfillstyle(1,0);
	floodfill(1,1,1);
	setcolor(GREEN);
	settextstyle(1,0,5);
	outtextxy(150,50,"TIC TAC TOE");
	setcolor(WHITE);
	rectangle(150,100,250,200);
	rectangle(250,200,350,300);
	rectangle(350,300,450,400);
	rectangle(350,100,450,200);
	rectangle(150,300,250,400);
	rectangle(250,100,350,200);
	rectangle(150,200,250,300);
	rectangle(350,200,450,300);
	rectangle(250,300,350,400);
}

int checkwin()
{
	if(square[1]==square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square [5] && square[5] == square[6])
		return 1;
	else if (square[7] == square [8] && square[8] == square[9])
		return 1;
	else if (square[1] == square [4] && square [4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] !='1' && square[2] !='2' && square[3] !='3' && square[4] !='4' && square[5] !='5' && square[6] !='6' && square [7] !='7' && square[8] !='8' && square[9] !='9')
		return 0;
	else
		return 10;
}


void drawx()
{

	int i;
	setcolor(BLUE);
	for(i = 0;i<10;i++)
	{
		if(data[i]==1 && square[i]=='x')
		{

			switch(i)
			{
				case 1:
					line(160,110,240,190);
					line(240,110,160,190);
					break;
				case 2:
					line(260,110,340,190);
					line(340,110,260,190);
					break;
				case 3:
					line(360,110,440,190);
					line(440,110,360,190);
					break;
				case 4:
					line(160,210,240,290);
					line(240,210,160,290);
					break;
				case 5:
					line(260,210,340,290);
					line(340,210,260,290);
					break;
				case 6:
					line(360,210,440,290);
					line(440,210,360,290);
					break;
				case 7:
					line(160,310,240,390);
					line(240,310,160,390);
					break;
				case 8:
					line(260,310,340,390);
					line(340,310,260,390);
					break;
				case 9:
					line(360,310,440,390);
					line(440,310,360,390);
					break;
			}
		}
	}
}

void drawo()
{
	int i;
	setcolor(RED);
	for(i = 0;i<10;i++)
	{
		if(data[i]==1 && square[i]=='o')
		{

			switch(i)
			{
				case 1:
					circle(200,150,40);
					break;
				case 2:
					circle(300,150,40);
					break;
				case 3:
					circle(400,150,40);
					break;
				case 4:
					circle(200,250,40);
					break;
				case 5:
					circle(300,250,40);
					break;
				case 6:
					circle(400,250,40);
					break;
				case 7:
					circle(200,350,40);
					break;
				case 8:
					circle(300,350,40);
					break;
				case 9:
					circle(400,350,40);
					break;
			}
		}
	}
}


void celeb(int a);

int main()
{
	int player=1,end=10,choice;
	int gd =DETECT , gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	do
	{
		clrscr();
		board();
		drawx();
		drawo();
		if (player == 1)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("Player 1 Enter postion : ");
			scanf("%d",&choice);
			if(choice>9)
				goto last;
			if(data[choice]==0)
			{
				data[choice]=1;
				square[choice]='x';
				drawx(choice);
				player++;
			}
			else
			{
				printf("Invalid no or no already filled\n");
				getch();
			}
		}
		else
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("Player 2 Enter postion : ");
			scanf("%d",&choice);
			if(choice>9)
				goto last;
			if(data[choice]==0)
			{
				data[choice]=1;
				square[choice]='o';
				drawo();
				player--;
			}
			else
			{
				printf("Invalid no or no already filled\n");
				getch();
			}
		}
	end = checkwin();
	last:
	}while(end == 10);
	if (end==1)
	{
		if(player==2)
		{
			printf("Player 1 wins\n");
		}
		else
		{
			printf("Player 2 wins\n");
		}
	}
	else
	{
		printf("Game draw\n\n");
	}

	getch();
	closegraph();
	return 0;
}


