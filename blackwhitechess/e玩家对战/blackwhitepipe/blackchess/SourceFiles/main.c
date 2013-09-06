#include <stdio.h>
#include<stdlib.h>
#include "ui.h"

int main()
{
		char row,col,wwin,bwin;
		int count = 1;
		char board[15][15]= {0};	
		FILE*fin = NULL;
		FILE*fout = NULL;
		step_t computer,you,read;

		srandom(time(NULL));

		while(count < 112)
		{
				you = you_move(board,BLACK);	//¼º·½ÎªºÚ·½£»
				row = you.row;
				col = you.col;
				board[row][col] = BLACK;
				print_board( board );
				write_step("black.pipe",you);

				printf("¿%d¿¿¿¿¿%d¿%c¿\n",count,col+'A',row+'1');

		//		bwin = black_gamelow(board);
				bwin = gamelow(board,you);
				if(1 == bwin)
				{
						print_board( board );
						printf("¿¿¿¿¿\n");
						return 0;
				}
				read=read_step("white.pipe",WHITE);
				row = read.row;
				col = read.col;
				board[row][col] = WHITE;
				printf("whiterow =%d,whitekcol=%d\n",row,col);
				print_board( board );
				printf("¿%d¿¿¿¿¿%c¿%d¿\n",count,col+'A',row+'1');
	//			wwin = white_gamelow(board);
				wwin = gamelow(board,read);
				if(1 == wwin)
				{
						print_board( board );
						printf("¿¿¿¿¿\n");
						return 0;
				}
				count++;
}
return 0;
}


