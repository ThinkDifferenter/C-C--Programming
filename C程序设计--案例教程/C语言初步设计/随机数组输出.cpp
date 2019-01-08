#include<stdio.h>
#include<time.h>
#include<stdlib.h>
main()
{
	int a[4][5],b[5]={0},c[4]={0},i,j,sum=0;
	
	srand((unsigned)time(NULL));
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			sum+=a[i][j];
			b[j]+=a[i][j];
			c[i]+=a[i][j];
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("%7d\n",c[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("%5d",b[i]);
	}
	printf("%7d\n",sum);

}
