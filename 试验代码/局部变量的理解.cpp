#include<stdio.h>
//变量作用域的理解
static int i=1000;
int main()
{
	int i=100;
	printf("for语句块的局部变量:\n");
	for(int i=1;i<4;i++)//for块里面的局部变量 
	{
		printf("%d\t",i);
	}
	printf("\n独立块里面的局部变量:\n");
	{
		int i=10;
		printf("%d\n",i);
	}
	printf("main函数里面的局部变量:\n"); 
	printf("%d\n\n",i);
	printf("全局变量i=%d\n",i);
	return 0;
}