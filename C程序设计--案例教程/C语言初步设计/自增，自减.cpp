#include<stdio.h>
main()
{
	int a=2,b=4;
	int c,d;
	
	c=a++;
	d=b--;
	
	printf("a=%d,b=%d\n",a,b);
	printf("c=%d,d=%d\n",c,d);
	
	return 0;
	
}
