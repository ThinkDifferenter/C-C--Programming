#include<stdio.h>
int add(int n);
int main()
{
	int i;
	printf("input i:");
	scanf("%d",&i);
	printf("the sum is %d\n",add(i));
	return 0;	
}
int add(int n)
{
	int sum=0;
	if(n==1)
	{
		sum=1;
	}
	else if(n>1)
	{
		sum=n+add(n-1);
	}
	return sum;
} 