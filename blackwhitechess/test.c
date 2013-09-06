#include<stdio.h>
#include<stdlib.h>

char lower(char a)
{
	if(a >= 'a'&&a <= 'z')
		return a - 32;
	else
		return a;
}

int main()
{
	char row,col;
	int buf[10]={0};

	scanf("%c%d",&col,&row);
	buf[0]=lower(col)-'A';
	buf[1]=row-'1';
	buf[2]='\n';

	printf("col=%c,row=%d\n",buf[0]+'A',buf[1]+'1');
	return 0;
}
