#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

char game[3][3];
char A[20],B[20];

char getat(int);
void putat(int,char);
void nocomp();
void winner();
void comp();
void think();
void printscreen();

void main()
{
int i,j,k,in;
system("cls");
k=1;
printf("\t\t\t\tWelcome to Tic-Tac-Toe \nPositions are as follows:\n");
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
		printf("%d\t\t",k++);

	printf("\n");
}
for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		game[i][j]='_';
printf("Press 1 to play against computer or 2 for two players:");
scanf("%d",&in);
if(in==2)
	nocomp();
else if(in==1)
	comp();
else
	main();
printf("\nMatch is DRAW");
getch();
}

char getat(int x)
{
char dis;
switch(x)
{
case 1:dis=game[0][0]; break;
case 2:dis=game[0][1]; break;
case 3:dis=game[0][2]; break;
case 4:dis=game[1][0]; break;
case 5:dis=game[1][1]; break;
case 6:dis=game[1][2]; break;
case 7:dis=game[2][0]; break;
case 8:dis=game[2][1]; break;
case 9:dis=game[2][2]; break;
default:dis='n';
}
return dis;
}

void putat(int x,char y)
{
switch(x)
{
case 1:game[0][0]=y; break;
case 2:game[0][1]=y; break;
case 3:game[0][2]=y; break;
case 4:game[1][0]=y; break;
case 5:game[1][1]=y; break;
case 6:game[1][2]=y; break;
case 7:game[2][0]=y; break;
case 8:game[2][1]=y; break;
case 9:game[2][2]=y; break;

}
}

void nocomp()
{
int i,j,k,ch;
char r;
gets(A);
printf("Enter name of first player:");
gets(A);
strupr(A);
printf("Enter name of second player:");
gets(B);
strupr(B);
printf("\nPress any key to play game");
getch();

for(k=0;k<9;k++)
{
	printscreen();

	if(k%2==0)
		printf("\nPlayer %s enter your choice:",A);
	else
		printf("\nPlayer %s enter your choice:",B);
	scanf("%d",&ch);
	r=getat(ch);
	if(r=='_')
	{
		if(k%2==0)
			putat(ch,'0');
		else
			putat(ch,'1');
	}
	else
	{
		printf("Invalid Choice. Retry");
		k--;
	}
	winner();
}
}

void winner()
{
int i;
printscreen();
for(i=0;i<3;i++)
		if(game[0][i]=='0' && game[1][i]=='0' && game[2][i]=='0')
		{
			printf("Player %s wins the match",A);
			getch();
			exit(1);
		}
	for(i=0;i<3;i++)
		if(game[i][0]=='0' && game[i][1]=='0' && game[i][2]=='0')
		{
			printf("Player %s wins the match",A);
			getch();
			exit(0);
		}

	for(i=0;i<3;i++)
		if(game[0][i]=='1' && game[1][i]=='1' && game[2][i]=='1')
		{
			printf("Player %s wins the match",B);
			getch();
			exit(0);
		}
	for(i=0;i<3;i++)
		if(game[i][0]=='1' && game[i][1]=='1' && game[i][2]=='1')
		{
			printf("Player %s wins the match",B);
			getch();
			exit(1);
		}

	if(game[0][0]=='0' && game[1][1]=='0' && game[2][2]=='0')
	{
		printf("Player %s wins the match",A);
		getch();
		exit(1);
	}
	if(game[0][0]=='1' && game[1][1]=='1' && game[2][2]=='1')
	{
		printf("Player %s wins the match",B);
		getch();
		exit(1);
	}

	if(game[0][2]=='0' && game[1][1]=='0' && game[2][0]=='0')
	{
		printf("Player %s wins the match",A);
		getch();
		exit(1);
	}
	if(game[0][2]=='1' && game[1][1]=='1' && game[2][0]=='1')
	{
		printf("Player %s wins the match",B);
		getch();
		exit(1);
	}
}

void comp()
{
int i,j,k,ch;
char r;
gets(A);
printf("Enter player name:");
gets(A);
strupr(A);
strcpy(B,"comp");
strupr(B);

printf("\nPress any key to play game");
getch();

for(k=0;k<9;k++)
{
	printscreen();

	if(k%2!=0)
	{
		printf("\nPlayer %s enter your choice:",A);
		scanf("%d",&ch);
		r=getat(ch);
		if(r=='_')
			 putat(ch,'0');
		else
		{
			printf("Invalid Choice. Retry");
			k--;
		}
		winner();
	}
	else
		{
		       think();
		       winner();
		}
}
}

void think()
{
	int i,j,cou;
	if(getat(5)=='_')
	{
		putat(5,'1');
		return;
	}
	//sleep(1);
//self horizontal
	for(i=0;i<3;i++)
	{
		cou=0;
		for(j=0;j<3;j++)
			if(getat(i*3+j+1)=='1')
				cou++;
		if(cou==2)
		{
			for(j=0;j<3;j++)
				if(getat(i*3+j+1)=='_')
				{
					putat(i*3+j+1,'1');
					return;
				}
		}
	}
//horizontal
	for(i=0;i<3;i++)
	{
		cou=0;
		for(j=0;j<3;j++)
			if(getat(i*3+j+1)=='0')
				cou++;
		if(cou==2)
		{
			for(j=0;j<3;j++)
				if(getat(i*3+j+1)=='_')
				{
					putat(i*3+j+1,'1');
					return;
				}
		}
	}


//self veritcal
	for(i=0;i<3;i++)
	{
		cou=0;
		for(j=0;j<3;j++)
			if(getat(i+j*3+1)=='1')
				cou++;
		if(cou==2)
		{
			for(j=0;j<3;j++)
				if(getat(j*3+i+1)=='_')
				{
					putat(j*3+i+1,'1');
					return;
				}
		}
	}
//vertical
	for(i=0;i<3;i++)
	{
		cou=0;
		for(j=0;j<3;j++)
			if(getat(j*3+i+1)=='0')
				cou++;
		if(cou==2)
		{
			for(j=0;j<3;j++)
				if(getat(j*3+i+1)=='_')
				{
					putat(j*3+i+1,'1');
					return;
				}
		}
	}
//self diagonal
	cou=0;
	for(i=1;i<10;i=i+4)
		if(getat(i)=='1')
			cou++;
	if(cou==2)
		for(i=1;i<10;i=i+4)
			if(getat(i)=='_')
			{
				putat(i,'1');
				return;
			}
//diagonal
	cou=0;
	for(i=1;i<10;i=i+4)
		if(getat(i)=='0')
			cou++;
	if(cou==2)
		for(i=1;i<10;i=i+4)
			if(getat(i)=='_')
			{
				putat(i,'1');
				return;
			}
//selfulta diagonal
	cou=0;
	for(i=3;i<8;i=i+2)
		if(getat(i)=='1')
			cou++;
	if(cou==2)
		for(i=3;i<8;i=i+2)
			if(getat(i)=='_')
			{
				putat(i,'1');
				return;
			}
//ulta diagonal
	cou=0;
	for(i=3;i<8;i=i+2)
		if(getat(i)=='0')
			cou++;
	if(cou==2)
		for(i=3;i<8;i=i+2)
			if(getat(i)=='_')
			{
				putat(i,'1');
				return;
			}
//corner
if(getat(1)=='_')
{
	putat(1,'1');
	return;
}
if(getat(7)=='_')
{
	putat(7,'1');
	return;
}

if(getat(3)=='_')
{
	putat(3,'1');
	return;
}

if(getat(9)=='_')
{
	putat(9,'1');
	return;
}


//nothink
	for(i=1;i<10;i++)
	{
		if(getat(i)=='_')
		{
			putat(i,'1');
			return;
		}
	}

}

void printscreen(){
    system("cls");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%c\t\t",game[i][j]);
		printf("\n");
	}
}
