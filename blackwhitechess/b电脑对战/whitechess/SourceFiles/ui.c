#include <stdio.h>
#include "ui.h"

//打印列标题, A B C ....
static void print_col_title()
{
	int col;

	printf("   "); //3个空格
	for( col=0; col<15; col++ )
	{	
		printf(" %c", 'A'+col); 
	}
	putchar('\n');
}

//打印棋盘及棋子( . O X )
void print_board( char a[15][15] )
{
	int row, col;

	print_col_title(); //打印列标题

	//打印各行
	for( row = 0; row<15; row++ )
	{
		printf("%3d", row+1); //行号

		for( col=0; col<15; col++ )
		{
			if( 7==col && 7==row && 0 == a[row][col])
			{
				printf(" +");  // + 标记棋盘中心
				continue;
			}

			if( BLACK == a[row][col] )
				printf(" X");
			else if ( WHITE == a[row][col] )
				printf(" O");
			else
				printf(" .");
		}

		printf("%3d\n", row+1); //行号
	}

	print_col_title(); //最后一行，打印列标题
}


