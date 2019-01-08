#include<stdio.h>
int main()
{
	int max(int i,int j);
	int min(int i,int j);
	int add(int i,int j);
	void process(int i,int j,int (*fun)(int i,int j));//函数作参数用指针代替 
	int a,b;
	printf("inter a,b:");
	scanf("%d %d",&a,&b);
	printf("max=");
	process(a,b,max);
	printf("min=");
	process(a,b,min);
	printf("sum=");
	process(a,b,add);
	
} 
int max(int i,int j)
{
	if(i>j)
	{
		return i;
	}
	else
	{
		return j;
	}
}
int min(int i,int j)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
{
	if(i<j)
	{
		return i;
	}
	else
	{
		return j;
	}
}
int add(int i,int j)
{
	return i+j;
}
void process(int i,int j,int (*fun)(int i,int j))
{
	int result;
	result=(*fun)(i,j);
	printf("%d\n",result);
}