#include<stdio.h>
#include<math.h>
#define pi 3.1415926/180.0//弧度制 
int main()
{
	char gr[70][100];
	int i,j,y1,y2;
	
	
	for(i=0;i<37;i++)
	{
		for(j=0;j<62;j++)
		{
			gr[i][j]=' ';
			if(j==30)
			{
				gr[i][j]='|';
			}
			gr[i][61]='\0';
		}
	}
	for(i=0;i<361;i+=10)
	{
		y1=(int)(sin(i*pi)*30+30);//30 与坐标轴的宽度有关系 
		y2=(int)(cos((2*i+30)*pi)/2*30+30);//加 30将图像向右移 30单位 
		gr[i/10][y1]='*';
		gr[i/10][y2]='+';
	}
	for(i=0;i<61;i++)
	{
		printf("%c",'-');
	}
	printf("\n");
	for(i=0;i<37;i++)
	{
		printf("%s\n",gr[i]);//降维！ 
	}
	for(i=0;i<61;i++)
	{
		printf("%c",'-');
	}
	printf("\n");
	return 0;
}