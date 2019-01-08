#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned)time(NULL));
	int i,j,row1=0,colum1=0,row2=0,colum2=0,max,min;
	int a[5][6];
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			a[i][j]=rand()%100+1;
		}
	}
	printf("Show array:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%d\t",a[i][j]);
		}
	}
	printf("\n\n");
	max=min=a[0][0];
	for(i=0;i<5;i++)
	{n
		for(j=0;j<6;j++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
				row1=i;
				colum1=j;
			}
			if(a[i][j]<min)
			{
				min=a[i][j];
				row2=i;
				colum2=j;
			}		
		}
	}
	printf("该二维数组中的最大值是%d行%d列的%d\n",row1,colum1,max);
	printf("该二维数组中的最小值是%d行%d列的%d\n",row2,colum2,min);
	return 0; 
} 