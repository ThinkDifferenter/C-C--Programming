#include<stdio.h>
#define MAX(a,b) (a)>(b)?(a):(b)
int main()
{
	int i=1;
	int j=2;
	int k=MAX(i,j);
	printf("the max is %d\n",k);
	return 0;
}