#include<stdio.h>
#include<time.h>
int main()
{
	clock_t i=clock();
	int a=100000000;
	while(a>=0)
	{
		a--;
	}
	printf("a=%d\n",a);
	clock_t j=clock();
	printf("clock 1=%f\n",(double)i/CLOCKS_PER_SEC);
	printf("clock 2=%f\n",(double)j/CLOCKS_PER_SEC);
	printf("the time is %f s\n",(double)(j-i)/CLOCKS_PER_SEC);
	return 0;
}