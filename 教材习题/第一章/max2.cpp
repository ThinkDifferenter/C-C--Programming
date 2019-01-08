#include<stdio.h>
int max(int i,int j,iny k)
{
	return i>j?(i>k?i:k):(j>k?j:k);
}
int main()
{
	int i,j,k;
	printf("inter three number i,j,k:");
	scanf("%d %d %d"&i,&j,&k);
	printf("the max is %d\n",max(i,j,k));
	return 0;
}