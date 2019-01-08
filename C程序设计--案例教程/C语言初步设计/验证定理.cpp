#include<stdio.h>
int main()
{
	int m,n;
	int sum,item;
	
	printf("input any integer:");
	scanf("%d",&m);
	
	sum+=item=m*(m-1)+1;
	for(n=1;n<m;n++)
	{
		item=item+2;
		sum+=item;
	}
	if(sum==m*m*m)
	{
		printf("reght!\n");
	}
	else
	{
		printf("error!\n");
	}
	return 0;
}