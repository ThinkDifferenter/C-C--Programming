#include<stdio.h>
#include<stdarg.h>
int add(int cnt,...);
int main()
{
	int sum=0;
	sum=add(6,2,3,4,5,6,7);
	printf("the sum is %d\n",sum);
	return 0;	
}
int add(int cnt,...)
{
	int sum=0;
	int i;
	va_list num;
	va_start(num,cnt);
	for(i=0;i<cnt;i++)
	{
		sum+= va_arg(num,int);
	}	
	va_end(num);
	return sum;
}