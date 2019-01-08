#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p=(int *)malloc(sizeof(int));
	printf("%p\n",p);
	free(p);	
	printf("%p\n",p);
	p=NULL;
	printf("%p\n",p);
	return 0;
}