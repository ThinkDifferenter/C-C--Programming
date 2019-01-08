#include<stdio.h>
int main()
{
	int m,n,i,j;
	printf("inter n,m:");
	scanf("%d %d",&n,&m);
	i=m%n;
	while(i!=0)
	{
		m=n;
		n=i;
		i=m%n;
	}
	printf("m和n的最大公约数为:%d\n",n);
	return 0;
}