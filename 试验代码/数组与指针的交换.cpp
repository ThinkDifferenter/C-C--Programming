#include<stdio.h>
int main()
{
	int a[10];
	a[6]=10;
	6[a]=10;
	printf("%d\n",a[6]);
	printf("%d\n",6[a]);
	printf("%d\n",*(a+6));
	printf("%d\n",*(6+a));
	return 0;
} 