#include<stdio.h>
int max(int i,int j)
{
	return i>j?i:j;
}
int main()
{
	int i,j,k;
	printf("inter three number i,j,k:");
	scanf("%d %d %d"&i,&j,&k);
	printf("the max is %d\n",max(i,max(j,k)));
	return 0;
}