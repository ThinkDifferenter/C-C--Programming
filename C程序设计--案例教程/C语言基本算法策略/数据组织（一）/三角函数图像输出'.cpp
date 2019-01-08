#include<stdio.h>
#include<math.h>
#define pi 3.1415926/180.0
int main()
{
	char gr[41][38];
	int i,j,y1,y2;
	
	for(i=0;i<41;i++)
	{
		for(j=0;j<38;j++)
		{
			gr[i][j]=' ';
			if(i==20)
			{
				gr[i][j]='-';
			}
			gr[i][37]='\0';
		}
	}
	for(i=0;i<361;i+=10)
	{
		y1=-(int)(sin(i*pi)*20-20);
		y2=-(int)(cos((2*i+30)*pi)/2*20-20);
		gr[y1][i/10]='*';
		gr[y2][i/10]='.';
	}
	for(i=0;i<41;i++)
	{
		printf("%s\n",gr[i]);
	}
	return 0;
} 