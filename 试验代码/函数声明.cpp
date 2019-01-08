#include<stdio.h>
int main()
{
	int i=3;
	int j=4;
	printf("the max is %d\n",max(i,j));
	return 0;
} 
int max(int i,int j)
{
	return i>j?i:j;
}