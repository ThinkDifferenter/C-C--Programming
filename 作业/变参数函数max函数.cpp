#include<stdio.h>
#include<stdarg.h>
int max(int cnt,...);
int main()
{
	int i;
	i=max(3,1,2,3);
	printf("the max is %d\n",max);
	return 0;
}
int max(int cnt,...)
{
	int i,m=0;
	va_list num;
	va_start(num,cnt);
	for(i=0;i<cnt;i++)
	{
		if(va_arg(num,int)>=m)
		{
			m=va_arg(num,int);
		}
	}
	va_end(num);
	return m;
}