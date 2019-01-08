#include<stdio.h>
#include<time.h>
int main()
{
	clock_t i=clock();
	int a=0;
	while(a>=0)
	{
		a++;
	}
	printf("a=%d\n",a);
	clock_t j=clock();
	printf("the time is %f s\n",(double)(j-i)/CLOCKS_PER_SEC);
	return 0;
}