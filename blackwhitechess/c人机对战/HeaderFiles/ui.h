#ifndef __CHESS_UI_H__
#define __CHESS_UI_H__

#ifdef __cplusplus
extern "C" {
#endif


#define NOTHING 0
#define BLACK   1
#define WHITE   2

		void print_board( char board[15][15] );

		typedef	struct step
		{
				char player;
				char row;
				char col;	
		} step_t;
		extern char lower(char a);
		extern step_t computer_move(char board[15][15],char player);
		extern step_t you_move(char board[15][15],char player);
	//	extern void maxscore(char a[15][15],char b[15][15],int player);		
		extern int gamelow(char a[15][15],step_t s);
		extern void scoresum(char a[15][15],int b[15][15],int player);		
		extern step_t chessjudge(int b1[15][15],int b2[15][15],int player);
#ifdef __cplusplus
}
#endif

#endif
