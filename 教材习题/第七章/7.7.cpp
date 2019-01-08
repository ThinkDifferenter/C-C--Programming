#include<stdio.h>
int main()
{
	int n,flag=0;
	printf("Please input array's wild: ");
	scanf("%d",&n);
	int a[n][n];
	int Sum1[n],Sum2[n];
	int sum1=0,sum2=0;
	int i,j,k=0;
	//每行列的和数组初始化 
	for(i=0;i<n;i++)
	{
		Sum1[i]=0;
		Sum2[i]=0;
	}	
	printf("input array:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//计算每行的和 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			Sum1[k++]=a[i][j];
		}
	}
	k=0;
	//计算每列的和 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			Sum2[k++]=a[j][i];
		}
	}
	//计算主对角线元素的和 
	for(i=0;i<n;i++)
	{
		sum1+=a[i][i];
	}
	//数组转置 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=a[j][i];
		}
	}
	//计算副对角线元素的和 
	for(i=0;i<n;i++)
	{
		sum2+=a[i][i];
	}
	//判断每行每列是否都和主副对角线元素和相等 
	for(i=0;i<n;i++)
	{
		if(Sum1[i]==Sum2[i]&&sum2==sum1&&sum1==Sum1[i])
		{
			flag=1;
		}
		else
		{
			printf("NO!\n");
			break;
		}
	}
	if(flag==1)
	{
		printf("YES!\n");
	}
	return 0;
}