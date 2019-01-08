#include<stdio.h>
int max(int i,int j)
{
	return i>j?i:j;
}
int main()
{
	int i,j,k,l;
	int Max1,Max2;
	printf("Please input four number :\n");
	scanf("%d %d %d %d",&i,&j,&k,&l);
	Max1=max(i,max(j,max(k,l)));
	Max2=max(max(i,j),max(k,l)); 
	printf("the max is %d\n",Max1);
	printf("the max is %d\n",Max2);
	return 0;
}