#include<stdio.h>
#include "ui.h"

void maxscore(char a[15][15],char b [15][15],int player)//the max score 
{
	int row,col,i,j;
	int max = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;

	for(row = 0;row < 15;row++)
	{
		for(col = 0;col < 15;col++)
		{
			b[row][col] = 0;
		}
	}

	for(row = 0;row < 15;row++)
	{
		for(col = 0;col < 15;col++)
		{
			if(NOTHING==a[row][col])
			{
				//line1 score col++
				i = 0;
				j = 1;
				while(player==a[row+i][col+j])
				{
					if((col+j)>14)
						break;
					count1++;
					j++;
				}
				//line1 score col--
				i = 0;
				j = -1;
				while(player==a[row+i][col+j])
				{
					if((col+j)<0)
						break;
					count1++;
					j--;
				}


				//line2 score row-- col++
				i = -1;
				j = 1;
				while(player==a[row+i][col+j])
				{
					if((col+j)>14||(row+i)<0)
						break;
					count2++;
					i--;
					j++;
				}
				//line2 score row++ col--
				i = 1;
				j = -1;
				while(player==a[row+i][col+j])
				{
					if((col+j)<0||(row+i)>14)
						break;
					count2++;
					j--;
					i++;
				}


				//line3 score row--
				i = -1;
				j = 0;
				while(player==a[row+i][col+j])
				{
					if((row+i)<0)
						break;
					count3++;
					i--;
				}
				//line3 score row++
				i = 1;
				j = 0;
				while(player==a[row+i][col+j])
				{
					if((row+i)>14)
						break;
					count3++;
					i++;
				}


				//line4 score row-- col--
				i = -1;
				j = -1;
				while(player==a[row+i][col+j])
				{
					if((col+j)<0||(row+i)<0)
						break;
					count4++;
					i--;
					j--;
				}
				//line4 score row++ col++
				i = 1;
				j = 1;
				while(player==a[row+i][col+j])
				{
					if((col+j)>14||(row+i)>14)
						break;
					count4++;
					j++;
					i++;
				}

				max = count1;
				if(max < count2)
					max = count2;
				if(max < count3)
					max = count3;
				if(max < count4)
					max = count4;
				b[row][col] = max; 
				count1 = 0;
				count2 = 0;
				count3 = 0;
				count4 = 0;
				max = 0;
			}
		}
	}

	//	 	row	= 0;
	//		col = 0;
	//		i = 0;
	//		j = 0;
	//		max = 0;
	//		count = 0;
}

step_t chessjudge(char b1[15][15],char b2[15][15],int player)
{
	int row,col;// max1 :the max score of player1  max2: ......
	int row1 = 0;
  	int col1 = 0;
	int row2 = 0;
	int col2 = 0;
	int max1 = 0;
	int max2 = 0;
	step_t temp;

	for(row = 0;row < 15;row++)
	{
		for(col = 0;col < 15;col++)
		{
			if(b1[row][col]>max1)
			{
				max1 = b1[row][col];
				row1 = row;
				col1 = col;
			}
			if(b2[row][col]>max2)
			{
				max2 = b2[row][col];
				row2 = row;
				col2 = col;
			}
		}
	}	
	printf("max1score=%d,max2score=%d\n",max1,max2);
	if(max2 >= 3)
	{
		temp.player = player;	
		temp.row = row2;
		temp.col = col2;
		return temp;
	}
	else
	{	
		temp.player = player;	
		temp.row = row1;
		temp.col = col1;
		return temp;
	}

}


