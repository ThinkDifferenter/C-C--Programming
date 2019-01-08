#include<stdio.h>
void swap(int *p1,int *p2);
int main()
{
	int a,b;
	int *p1,*p2;
	printf("Please input a,b:");
	scanf("%d %d",&a,&b);
	p1=&a;
	p2=&b;
	if(a<b)
	{
		swap(p1,p2);
	}	
	printf("a=%d,b=%d\n",a,b);
	return 0; 
}
void swap(int *p,int *q)
{
	int *tmp;
	tmp=p;
	p=q;
	q=tmp;
}