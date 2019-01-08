#include<stdio.h>
int main()
{
	int a[6]={1,2,3,4,5,6};
	int b[2][3];
	int i,j,k=0;
	printf("一维数组:\n");
	for(i=0;i<6;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	printf("二维数组:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=a[k++];
		}
			
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	} 
	printf("\n");
	return 0;
}