#include<stdio.h>
int main()
{
	int a[3][3]={{1,2,3},{4,5,6,},{7,8,9}};
	int i,j;
	int sum=0;
	for(i=0;i<3;i++)
	{
		sum+=a[i][i];
	}
	//数组实质转置 
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=a[j][i];		
		}
	}
	//数组表面转置 
	//for(j=0;j<3;j++)
	//{
	//	for(i=0;i<3;i++)
	//	{
	//		printf("%d\t",a[j][i]); 
	//	}
	//	printf("\n");
	//} 
	for(i=0;i<3;i++)
	{
		sum+=a[i][i];
	}
	printf("the sum is %d\n",sum-a[1][1]);
	return 0;
}
