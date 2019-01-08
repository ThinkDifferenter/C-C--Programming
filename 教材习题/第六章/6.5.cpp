#include<stdio.h>
int main()
{
	int i;
	int sum1=0;
	long  sum2=0;
	double sum3=0.0;
	for(i=1;i<100;i++)
	{
		sum1+=i;
	}
	for(i=1;i<50;i++)
	{
		sum2+=i*i;
	}
	for(i=1;i<10;i++)
	{
		sum3+=1.0/i;
	}
	printf("sum1 is %d\n",sum1);
	printf("sum2 is %ld\n",sum2);
	printf("sum3 is %f\n",sum3);
	return 0;
}