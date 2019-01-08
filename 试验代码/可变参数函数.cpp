#include<stdio.h>
#include<stdarg.h>
int power(int cnt,...);
int main()
{
	int i,j;
	printf("Please input the count :");
	scanf("%d",&i);
	int a[i];
	printf("Please input the number :\n");
	for(j=0;j<i;j++)
	{
		//printf("input the number %d num:",j+1);
		scanf("%d",a[j]);
	}
	printf("the result is %d\n",power(i,a));
	return 0;
}
int power(int cnt,...)
{
	int i,result=1;
	va_list cheng;
	va_start(cheng,cnt);
	for(i=0;i<cnt;i++)
	{
		result*=va_arg(cheng,int);
	}
	va_end(cheng);
	return result;
}