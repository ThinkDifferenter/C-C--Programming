#include<stdio.h>
void fanxu(int x[],int n);
int main()
{
	int i,a[5]={2,3,5,1,6};
	printf("the original array:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}	
	printf("\n");
	fanxu(a,5);
	
	printf("the array has been inverted:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
void fanxu(int x[],int n)
{
	int *p,tmp,*i,*j,k;
	k=(n-1)/2;
	i=x;//数组x的首地址 
	j=x+n-1;//数组x的最后一个数的地址 
	p=x+k;// 数组x的中间一个数的地址 
	for(;i<p;i++,j--)
	{
		tmp=*i;
		*i=*j;
		*j=tmp;
	}
} 