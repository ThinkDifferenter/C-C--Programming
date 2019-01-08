#include<stdio.h>
int main()
{
	int i;
	for(i=0;i<10;i++,i++)
	{
		printf("%d\t",i);
	}
	printf("\n\n");
	for(i=0;i<10;i+=2)
	{
		printf("%d\t",i);
	}
	printf("\n");
	return 0;
}