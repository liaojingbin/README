#include <stdio.h>
#include<stdlib.h>
#include "ui.h"

int main()
{
	char row,col,row1,col1,wwin,bwin;
	step_t white,black;
	int count = 0;
	int i,j;
	char board[15][15]= {0};	
	char score1[15][15]= {0};	
	char score2[15][15]= {0};	
	FILE*fin = NULL;
	FILE*fout = NULL;

//	srandom(time(NULL));

	while(count <= 112)
	{

	//		printf("¿%d¿¿¿¿¿¿%c%d\n",count,col+97,row+1);
	//		print_board( board );
	//		printf("¿%d¿¿¿¿¿¿%c%d\n",count,col1+97,row1+1);
			black = read_step("black.pipe",BLACK);
			row = black.row;
			col = black.col;
			board[row][col] = BLACK;	
			printf("The%dround blackchess go to the:%c%d\n",count,col+97,row+1);
			print_board( board );
			printf("The%dround whitechess go to the:%c%d\n",count,col1+97,row1+1);
	//		printf("¿%d¿¿¿¿¿%d¿%c¿\n",count,col,row+'A');
	//		bwin = black_gamelow(board);
	
			bwin = gamelow(board,black);
			if(1 == bwin)
			{
				print_board( board );
				printf("blackchess is the winner!\n");
				return 0;
			}
			
			for(i = 0;i < 0xfff;i++)
			{
				for(j = 0;j < 0xffff;j++);
			}
			
		//	print_board( board );
		//	you = you_move(board,WHITE);	//¼º·½Îª°×·½£»
			
			maxscore(board,score1,BLACK);
			maxscore(board,score2,WHITE);
			white = chessjudge(score1,score2,WHITE);
			row = white.row;
			col = white.col;
			board[row][col] = white.player;
			print_board( board );
		//	maxscore(board,score2,WHITE);
			
		//	row = white.row;
		//	col = white.col;
		//	board[row][col] = WHITE;
			write_step("white.pipe",white);
//			printf("¿%d¿¿¿¿¿%d¿%c¿\n",count,col,row+'A');
//			wwin = white_gamelow(board);
			wwin = gamelow(board,white);
			if(1 == bwin)
			{
				print_board( board );
				printf("whitechess is the winner!\n");
				return 0;
			}
			count++;	
	}
	return 0;
}



