#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned)time(NULL));
	int i=rand()%100000+1;
	int j=rand()%100+1;
	printf("%d.%d\n",i,j);
	return 0;	
}