#include<stdio.h>
#include<stdarg.h>
int sum(int cnt,...);
int main()
{
	printf("the result of sum is %d\n",sum(7,1,2,3,4,5,6,7));
	return 0;
}
int sum(int cnt,...)
{
	int i,result=0;
	va_list add;
	va_start(add,cnt);
	for(i=0;i<cnt;i++)
	{
		result+=va_arg(add,int);
	}
	return result;
}