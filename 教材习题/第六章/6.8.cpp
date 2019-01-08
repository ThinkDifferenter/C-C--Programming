#include<stdio.h>
int main()
{
	int i;
	double j=2.0,k=3.0,t;
	double sum=2.0/1+3.0/2;
	for(i=3;i<=20;i++)
	{
		t=j+k;
		sum+=t/i;
		
		j=k;
		k=t;	
	}
	printf("the sum is %.2f\n",sum);
	return 0;
}
