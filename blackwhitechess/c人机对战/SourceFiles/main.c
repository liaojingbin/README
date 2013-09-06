#include <stdio.h>
#include<stdlib.h>
#include "ui.h"

int main()
{
	char row,col,wwin,bwin;
	step_t computer,you;
	int player;
	int flag = 0;
	int count = 0;
	char board[15][15]= {0};	
	int score1[15][15]={0};
	int score2[15][15]={0};
	int m,n;
	//		srandom(time(NULL));

	print_board( board );
	while(count < 225)
	{

		//		if(0 == flag)
		//		{
		you = you_move(board,BLACK);	

		row = you.row;
		col = you.col;

		board[row][col] = you.player;

		print_board( board );
//		maxscore(board,score1,BLACK);	

		printf("yourboard = %d\n",board[col][row]);

		bwin = gamelow(board,you);
		if(1 == bwin)
		{
			print_board( board );
			printf("black are the winner!\n");
			return 0;
		}
		//			flag = 1;
		//		}

		//		if(1 == flag)
		//		{




//		maxscore(board,score1,BLACK);	
//		maxscore(board,score2,WHITE);

		scoresum(board,score1,BLACK);	
		scoresum(board,score2,WHITE);

		printf("*************whilescore***************\n");
		for(m = 0;m < 15;m++)
		{
			for(n = 0;n < 15;n++)
			{
				printf("%4d",score2[m][n]);
			}
			printf("\n");
		}
		printf("**************************************\n");
		printf("************blackscore****************\n");
		for(m = 0;m < 15;m++)
		{
			for(n = 0;n < 15;n++)
			{
				printf("%4d",score1[m][n]);
			}
			printf("\n");
		}	
		printf("**************************************\n");

		computer = chessjudge(score1,score2,WHITE);
		row = computer.row;
		col = computer.col;	
		board[row][col] = computer.player;
		print_board( board );
		wwin = gamelow(board,computer);
		if(1 == wwin)
		{
			print_board( board );
			printf("computer are the winner!\n");
			return 0;
		}	

		//			flag = 0;	
		count++;	
		//		}

		printf("count=%d\n",count);//test



	}
	return 0;
}
