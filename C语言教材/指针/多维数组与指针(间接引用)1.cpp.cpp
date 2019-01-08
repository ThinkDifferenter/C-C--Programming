#include<stdio.h>
int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int *p;
	for(p=*a;p<*a+12;p++)
	{
		if((p-*a)%4==0)
		{
			printf("\n");
		}
		printf("%d\t",*p);
	}
	printf("\n");
}