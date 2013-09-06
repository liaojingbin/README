#include <stdio.h>
#include<stdlib.h>
#include "ui.h"

int main()
{
		char row,col,wwin,bwin;
		char row1 = 0;
		char col1 = 0;
		int count = 1;
		int i,j;
		char board[15][15]= {0};
		int score1[15][15]={0};
		int score2[15][15]={0};	
		FILE*fin = NULL;
		FILE*fout = NULL;
		step_t white,black,read;

		//		srandom(time(NULL));

		while(count <= 112)
		{

				//		you = you_move(board,BLACK);	//¼º·½ÎªºÚ·½£»
				printf("The%dround blackchess go to the:%c%d\n",count,col+97,row+1);
				print_board( board );
				printf("The%dround whitechess go to the:%c%d\n",count,col1+97,row1+1);

				scoresum(board,score1,BLACK);	
				scoresum(board,score2,WHITE);

				black = chessjudge(score1,score2,BLACK);
				row = black.row;
				col = black.col;
				board[row][col] = BLACK;
				write_step("black.pipe",black);

				//				printf("¿%d¿¿¿¿¿%d¿%c¿\n",count,col,row+'A');

				//		bwin = black_gamelow(board);
				bwin = gamelow(board,black);
				if(1 == bwin)
				{
						print_board( board );
						printf("blackchess is the winner! \n");
						return 0;
				}
				print_board( board );

				for(i = 0;i < 0xfff;i++)
				{
						for(j = 0;j < 0xffff;j++);
				}				

				white=read_step("white.pipe",WHITE);
				row = white.row;
				col = white.col;
				board[row][col] = WHITE;
				//				printf("¿%d¿¿¿¿¿%d¿%c¿\n",count,row,col+'A');
				//			wwin = white_gamelow(board);
				wwin = gamelow(board,white);
				if(1 == wwin)
				{
						print_board( board );
						printf("whitechess is the winner!\n");
						return 0;
				}
				count++;
		}
		return 0;
}


