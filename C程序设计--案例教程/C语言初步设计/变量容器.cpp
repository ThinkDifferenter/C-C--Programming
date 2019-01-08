#include<stdio.h>

void swap(int a,int b);

main()
{
	int a=5;
	int b=6;
	swap(a,b);
	printf("a=%d\nb=%d\n",a,b);
	
	return 0;
}

void swap(int a,int b)

{
	int t=a;
	a=b;
	b=t;
}
