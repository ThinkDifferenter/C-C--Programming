#include<stdio.h>
struct wc
{
	int a;
	int *b;
}*p;
int main()
{
	int x0[]={11,12};
	int x1[]={31,32};
	static struct wc x[2]={100,x0,300,x1};
	p=x;
	printf("%d\n",*++((++p)->b));
	return 0;
}