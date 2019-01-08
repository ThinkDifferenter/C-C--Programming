#include<stdio.h>
int main()
{
	union date
	{
		int i;
		double j;
		int a[5];
	};
	date d;
	printf("the sizeof date is %d\n",sizeof(d));
	return 0;
}