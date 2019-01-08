#include<stdio.h>
main()
{
	//遍历二维数组！！ 
	//数组转置！！ 
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int i,j;
	//套路！ 
	printf("array a:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);//间距大小%nd 
		}
		printf("\n");
	}	
	printf("array a':\n");
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	//数组转置套路 
	printf("array a:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("array a‘:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%4d",a[j][i]);
		}
		printf("\n");
	}
}
