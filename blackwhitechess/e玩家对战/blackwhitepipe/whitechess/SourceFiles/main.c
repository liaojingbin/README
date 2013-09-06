#include <stdio.h>
#include<stdlib.h>
#include "ui.h"

int main()
{
	char row,col,wwin,bwin;
	int count = 0;
	char board[15][15]= {0};	
	FILE*fin = NULL;
	FILE*fout = NULL;

	srandom(time(NULL));

	while(count < 225)
	{
			step_t computer,you,read;
			read=read_step("black.pipe",BLACK);
			row = read.row;
			col = read.col;
			board[row][col] = BLACK;
			printf("blackrow =%d,blackcol=%d\n",row,col);	
			print_board( board );
			printf("¿%d¿¿¿¿¿%d¿%c¿\n",count,col,row+'A');
	//		bwin = black_gamelow(board);
			bwin = gamelow(board,read);
			if(1 == bwin)
			{
				print_board( board );
				printf("¿¿¿¿¿\n");
				return 0;
			}

			you = you_move(board,WHITE);	//¼º·½Îª°×·½£»

			row = you.row;
			col = you.col;
			board[row][col] = WHITE;
			print_board( board );
			write_step("white.pipe",you);
			printf("¿%d¿¿¿¿¿%d¿%c¿\n",count,col,row+'A');
//			wwin = white_gamelow(board);
			wwin = gamelow(board,you);
			if(1 == bwin)
			{
				print_board( board );
				printf("¿¿¿¿¿\n");
				return 0;
			}
			count++;	
	}
	return 0;
}



