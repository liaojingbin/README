#include <stdio.h>
#include<stdlib.h>
#include "ui.h"

int main()
{
		char row,col,wwin,bwin;
		int count = 0;
		char board[15][15]= {0};	

		srandom(time(NULL));

		while(count < 225)
		{
				int flag = 0;
				step_t computer,you;	
				if(0 == flag)
				{
						computer = computer_move(board,BLACK);	
						row = computer.row;
						col = computer.col;


						board[row][col] = computer.player;	
						col = col + 'A';

						printf("computerboard = %d\n",board[row][col]);

						printf("player = %d\n",computer.player);
						printf("computer.col = %c\n",col);
						printf("computer.row = %d\n",row+1);
						flag = 1;
				}

				print_board( board );

				//		bwin = black_gamelow(board);
				bwin = gamelow(board,computer);
				if(1 == bwin)
				{
						print_board( board );
						printf("computer are the winner!\n");
						return 0;
				}

				if(1 == flag)
				{
						you = you_move(board,WHITE);	

						row = you.row;
						col = you.col;


						board[row][col] = you.player;

						printf("yourboard = %d\n",board[col][row]);
						//	printf("buf = %d\n",buf[col][row]);
						//	printf("jjjm=%d,jjjn=%d\n",row,col);
						//	printf("player = %d\n",you.player);
						//	printf("you.row = %c\n",row);
						//	printf("you.col = %d\n",col);	
						//	printf("count = %d\n",count);

						//		wwin = white_gamelow(board);
						wwin = gamelow(board,you);
						if(1 == wwin)
						{
								print_board( board );
								printf("your are the winner!\n");
								return 0;
						}
						flag = 0;
						count++;	
				}
		}
		return 0;
}
