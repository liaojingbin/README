#include<stdio.h>
#include<stdlib.h>
#include"ui.h"

step_t computer_move(char a[15][15],char player)
{
	char row = 0;
	char col = 0;
	step_t computer;

	row = random()%15;
	col = random()%15;

	while(a[row][col]>NOTHING||row>15||row<0||col>15||col<0)
	{	

		row = 0;
		col = 0;
		row = random()%15;
		col = random()%15; 
	}
	computer.row = row;	
	computer.col = col;	
	computer.player = player;

	return computer;
}


step_t you_move(char a[15][15],char player)
{	
	int row = 0;
	int col = 0;
	step_t you;

	printf("pleace input your row and col:\n");
	scanf("%c%d",&col,&row);
	col = lower(col)-65;
	row = row-1;
	while(a[row][col]>NOTHING||row>15||row<0||col>15||col<0)
	{
		printf("erro!pleace input again:\n");

		row = 0;
		col = 0;
		scanf("%c%d",&col,&row);		
		col = lower(col)-65;
		row = row-1;
	}
	you.row = row;	
	you.col = col;
	you.player = player;
	return you;
}


int gamelow(char a[15][15],step_t s)
{	
	int count,row,col,player;


	count = 0;
	row = s.row;
	col = s.col;
	player = s.player;
	while(player==a[row][col])
	{
		count++;
		col++;
		if(col > 14)
			break;
	}//x++ 1

	row = s.row;
	col = s.col;	
	while(player==a[row][col-1])
	{
		count++;
		col--;
		if((col-1) < 0)
			break;
	}//x--  5
	if(count>=5)
		return 1;
//	printf("count1=%2d\n",count);
	count = 0;
	row = s.row;
	col = s.col;	
	while(player==a[row][col])
	{
		count++;
		col++;
		row--;
		if(col > 14||row < 0)
			break;
	}//x++,y-- 2  //a[y][x]

	row = s.row;
	col = s.col;	
	while(player==a[row+1][col-1])
	{
		count++;
		col--;
		row++;
		if((col-1) < 0||(row+1) > 14)
			break;
	}//x--,y++ 6
	if(count>=5)
		return 1;

//	printf("count2=%2d\n",count);
	count = 0;
	row = s.row;
	col = s.col;	
	while(player==a[row][col])
	{
		count++;
		row--;
		if(row < 0)
			break;
	}//y-- 3

	row = s.row;
	col = s.col;	
	while(player==a[row+1][col])
	{
		count++;
		row++;
		if((row+1) > 14)
			break;
	}//y++ 7
	if(count>=5)
		return 1;

//	printf("count3=%2d\n",count);
	count = 0;
	row = s.row;
	col = s.col;	
	while(player==a[row][col])
	{
		count++;
		row--;
		col--;
		if(row < 0||col < 0)
			break;
	}//x--,y-- 4

	row = s.row;
	col = s.col;	
	while(player==a[row+1][col+1])
	{
		count++;
		row++;
		col++;
		if((col+1) > 14||(row+1) > 14)
			break;
	}//x++,y++ 8
	if(count>=5)
		return 1;

//	printf("count4=%2d\n",count);
	col = 0;
	row = 0;
	count = 0;
	return 0;
}


void write_step(const char*path,struct step s)//写黑方棋步
{
	FILE*fp = fopen(path,"a");
	if(NULL==fp)
		printf("write chess is erro!!!");
	fprintf(fp,"%c%d\n",s.col+'A',s.row+1);
	fclose(fp);
}

struct step read_step(const char*path,char player)//读白方棋步
{
	step_t temp;
	char buf[5];
	FILE*fp = fopen(path,"r");

	if(NULL==fp)
		printf("read chess is erro!!!");
	fgets(buf,5,fp);
	temp.player = player;
	temp.col = buf[0]-'A';
	temp.row = atoi(buf+1)-1;
	printf("atoi+1=%d\n",atoi(buf+1)-1);
	fclose(fp);
	return temp;
}

char lower(char a)
{
	if(a >= 'a'&&a <= 'z')
		return a-32;
	else
		return a;
}
