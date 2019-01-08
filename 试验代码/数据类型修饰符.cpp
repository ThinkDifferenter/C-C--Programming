#include<stdio.h>
int main()
{
	unsigned int i=1;
	long int j=100;
	printf("%d\n",i);
	printf("%u\n",i);
	printf("%d\n",j);
	printf("%ld\n",j);
	printf("sizeof(i)=%d\n",sizeof(i));
	printf("sizeif(j)=%d\n",sizeof(j));
	return 0;
}