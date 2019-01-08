#include<stdio.h>
#define integer int
typedef int Integer;
typedef unsigned int NI;
int main()
{
	unsigned integer n =100;
	NI i=300;
//	unsigned Integer m =200;//typedef 不是简单的替换！！！ 
	printf("%d\n",n);
//	printf("%d\n",m);
	printf("%d\n",i);//typedef是为一种数据类型起别名，一定是数据类型！！！ 
	return 0; 
}