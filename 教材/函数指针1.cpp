#include<stdio.h>
int max(int i,int j);

int main()
{
	int (*p)(int i,int j);//定义一个指向函数的指针 
	p=max;//函数名对应的地址就是函数的入口地址 
	int a,b,c;
	printf("inter a,b:");
	scanf("%d %d %d",&a,&b,&c);
	c=(*p)(a,b);//通过指针调用函数 
	printf("the max of a,b is %d\n",c);
	return 0;	
} 
int max(int i,int j)
{
	int k;
	if(i>j)
	{
		return i;
	}
	else
	{
		return j;
	}
}