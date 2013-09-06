#include <stdio.h>
#include "ui.h"

//��ӡ�б���, A B C ....
static void print_col_title()
{
	int col;

	printf("   "); //3���ո�
	for( col=0; col<15; col++ )
	{	
		printf(" %c", 'A'+col); 
	}
	putchar('\n');
}

//��ӡ���̼�����( . O X )
void print_board( char a[15][15] )
{
	int row, col;

	print_col_title(); //��ӡ�б���

	//��ӡ����
	for( row = 0; row<15; row++ )
	{
		printf("%3d", row+1); //�к�

		for( col=0; col<15; col++ )
		{
			if( 7==col && 7==row && 0 == a[row][col])
			{
				printf(" +");  // + �����������
				continue;
			}

			if( BLACK == a[row][col] )
				printf(" X");
			else if ( WHITE == a[row][col] )
				printf(" O");
			else
				printf(" .");
		}

		printf("%3d\n", row+1); //�к�
	}

	print_col_title(); //���һ�У���ӡ�б���
}


