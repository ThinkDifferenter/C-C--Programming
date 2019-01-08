#include<stdio.h>
#define max(a,b) a>b?a:b
int main()
{
	int i,j,k;
	i=1;
	j=2;
	k=max(i,j);
	printf("the max is %d\n",k);
	return 0;
}