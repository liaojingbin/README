#include<stdio.h>
#include "ui.h"

void scoresum(char a[15][15],int b[15][15],int player)//the max score 
{
		int row,col,i,j;
		int sum = 0;
		int score1 = 0;//横线分数；
		int score2 = 0;//右斜线分数；
		int score3 = 0;//竖线分数；
		int score4 = 0;//左斜线分数；

		int countl = 0;//左累加数；
		int countr = 0;//右累加数；
		int borderl = 0;//左边界值；
		int borderr = 0;//右边界值；
		int scorel = 0;//左分值；
		int scorer = 0;//右分值；

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
								if((col+j)<=14)
								{
										while(player==a[row+i][col+j])
										{
												countr++;
												j++;
												if((col+j)>14)
														break;
										}///////
										switch(countr)//个数分值
										{
												case 0:scorer = 1;break;
												case 1:scorer = 10;break;
												case 2:scorer = 100;break;
												case 3:scorer = 1000;break;
												case 4:scorer = 10000;break;
												default:break;
										}
										if((col+j+1)<=14&&NOTHING==a[row+i][col+j+1])//边界分值
												borderr = scorer;
										else
												borderr = 0;
								}////////

								//line1 score col--
								i = 0;
								j = -1;
								if((col+j)>=0)
								{
										while(player==a[row+i][col+j])
										{
												countl++;
												j--;
												if((col+j)<0)
														break;
										}
										switch(countl)//个数分值
										{
												case 0:scorel = 1;break;
												case 1:scorel = 10;break;
												case 2:scorel = 100;break;
												case 3:scorel = 1000;break;
												case 4:scorel = 10000;break;
												default:break;
										}
										if((col+j-1)>=0&&NOTHING==a[row+i][col+j-1])//边界分值
												borderl = scorel;
										else
												borderl = 0;
								}
								score1 = scorel+borderl+scorer+borderr;
								scorel = 0;
								scorer = 0;
								borderl = 0;
								borderr = 0;
								countl = 0;
								countr = 0;

								//line2 score row-- col++
								i = -1;
								j = 1;
								if((row+i)>=0&&(col+j)<=14)
								{
										while(player==a[row+i][col+j])
										{
												countr++;
												i--;
												j++;
												if((col+j)>14||(row+i)<0)
														break;
										}/////
										switch(countr)//个数分值
										{
												case 0:scorer = 1;break;
												case 1:scorer = 10;break;
												case 2:scorer = 100;break;
												case 3:scorer = 1000;break;
												case 4:scorer = 10000;break;
												default:break;
										}
										if((row+i-1)>=0&&(col+j+1)<=14&&NOTHING==a[row+i-1][col+j+1])//边界分值
												borderr = scorer;
										else
												borderr = 0;
								}/////
								//line2 score row++ col--
								i = 1;
								j = -1;
								if((row+i)<=14&&(col+j)>=0)
								{
										while(player==a[row+i][col+j])
										{
												countl++;
												j--;
												i++;
												if((col+j)<0||(row+i)>14)
														break;
										}/////
										switch(countl)//个数分值
										{
												case 0:scorel = 1;break;
												case 1:scorel = 10;break;
												case 2:scorel = 100;break;
												case 3:scorel = 1000;break;
												case 4:scorel = 10000;break;
												default:break;
										}
										if((row+i+1)<=14&&(col+j-1)>=0&&NOTHING==a[row+i+1][col+j-1])//边界分值
												borderl = scorel;
										else
												borderl = 0;
								}/////
								score2 = scorel+borderl+scorer+borderr;
								scorel = 0;
								scorer = 0;
								borderl = 0;
								borderr = 0;
								countl = 0;
								countr = 0;


								//line3 score row--
								i = -1;
								j = 0;
								if((row+i)>=0)
								{
										while(player==a[row+i][col+j])
										{
												countr++;
												i--;
												if((row+i)<0)
														break;
										}/////
										switch(countr)//个数分值
										{
												case 0:scorer = 1;break;
												case 1:scorer = 10;break;
												case 2:scorer = 100;break;
												case 3:scorer = 1000;break;
												case 4:scorer = 10000;break;
												default:break;
										}
										if((row+i-1)>=0&&NOTHING==a[row+i-1][col+j])//边界分值
												borderr = scorer;
										else
												borderr = 0;
								}/////

								//line3 score row++
								i = 1;
								j = 0;
								if((row+i)<=14)
								{
										while(player==a[row+i][col+j])
										{
												countl++;
												i++;
												if((row+i)>14)
														break;
										}/////
										switch(countl)//个数分值
										{
												case 0:scorel = 1;break;
												case 1:scorel = 10;break;
												case 2:scorel = 100;break;
												case 3:scorel = 1000;break;
												case 4:scorel = 10000;break;
												default:break;
										}
										if((row+i+1)<=14&&NOTHING==a[row+i+1][col+j])//边界分值
												borderl = scorel;
										else
												borderl = 0;
								}/////
								score3 = scorel+borderl+scorer+borderr;
								scorel = 0;
								scorer = 0;
								borderl = 0;
								borderr = 0;
								countl = 0;
								countr = 0;


								//line4 score row-- col--
								i = -1;
								j = -1;
								if((row+i)>=0&&(col+j)>=0)
								{
										while(player==a[row+i][col+j])
										{
												countr++;
												i--;
												j--;
												if((col+j)<0||(row+i)<0)
														break;
										}/////
										switch(countr)//个数分值
										{
												case 0:scorer = 1;break;
												case 1:scorer = 10;break;
												case 2:scorer = 100;break;
												case 3:scorer = 1000;break;
												case 4:scorer = 10000;break;
												default:break;
										}
										if((row+i-1)>=0&&(col+i-1)>=0&&NOTHING==a[row+i-1][col+j-1])//边界分值
												borderr = scorer;
										else
												borderr = 0;
								}/////
								//line4 score row++ col++
								i = 1;
								j = 1;
								if((row+i)<=14&&(col+j)<=14)
								{
										while(player==a[row+i][col+j])
										{
												countl++;
												j++;
												i++;
												if((col+j)>14||(row+i)>14)
														break;
										}/////
										switch(countl)//个数分值
										{
												case 0:scorel = 1;break;
												case 1:scorel = 10;break;
												case 2:scorel = 100;break;
												case 3:scorel = 1000;break;
												case 4:scorel = 10000;break;
												default:break;
										}
										if((row+i+1)<=14&&(col+j+1)<=14&&NOTHING==a[row+i+1][col+j+1])//边界分值
												borderl = scorel;
										else
												borderl = 0;
								}/////
								score4 = scorel+borderl+scorer+borderr;
								scorel = 0;
								scorer = 0;
								borderl = 0;
								borderr = 0;
								countl = 0;
								countr = 0;

								sum = score1+score2+score3+score4;
								b[row][col] = sum;
								sum = 0;
								score1 = 0;
								score2 = 0;
								score3 = 0;
								score4 = 0;

						}
				}
		}
}

step_t chessjudge(int b1[15][15],int b2[15][15],int player)
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
		//if(max2 >= 3)
		if(max2 > 100)
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


