#include<stdio.h>
#include<math.h> 
int main()
{
	double x1,x2,a;
	printf("������Ҫ��������:");
	scanf("%lf",&a);
	x2=a/2;
	do
	{
		x1=x2;
		x2=(x1+a/x1)/2;
	}
	while(fabs(x1-x2)>=1e-5);
	printf("%f\n",x2);
	return 0;	
}