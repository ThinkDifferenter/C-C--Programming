#include<stdio.h>
main()
{
	//������ά���飡�� 
	//����ת�ã��� 
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int i,j;
	//��·�� 
	printf("array a:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);//����С%nd 
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
	//����ת����· 
	printf("array a:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("array a��:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%4d",a[j][i]);
		}
		printf("\n");
	}
}
