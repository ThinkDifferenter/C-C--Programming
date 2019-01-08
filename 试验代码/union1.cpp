#include<stdio.h>
int main()
{
	union  date
	{
		double a;
		int b;
		char ch;
	}d;
	d.a=0;
	d.b=100;
	d.ch='j';
	printf("the sizeof union is %d\n",sizeof(d));
	printf("%f\n",d.a);
	printf("%f\n",d.b);
	printf("%c\n",d.ch);
	return 0;
}