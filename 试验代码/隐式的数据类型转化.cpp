#include<stdio.h>
int main()
{
	char ch='A';
	printf("the sizeof ch is %d\n",sizeof(ch));
	int i='A';
	double j=1.0;
	i=i*ch;
	i=j*i;
	printf("the sizeof ch is %d\n",sizeof((int)ch));
	printf("the sizeof i is %d\n",sizeof(i));
	return 0;
}