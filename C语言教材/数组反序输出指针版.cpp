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
	i=x;//����x���׵�ַ 
	j=x+n-1;//����x�����һ�����ĵ�ַ 
	p=x+k;// ����x���м�һ�����ĵ�ַ 
	for(;i<p;i++,j--)
	{
		tmp=*i;
		*i=*j;
		*j=tmp;
	}
} 