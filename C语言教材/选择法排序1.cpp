#include<stdio.h>
void xunze(int a[],int n);
int main()
{
	int i,a[5]={2,3,5,1,6};
	printf("the original array:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}	
	printf("\n");
	
	xunze(a,5);
	
	printf("the array has been sorted:\n");
	
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
	
}
void xunze(int a[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		k=i;//╪гоб╫г╠Й 
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[k])
			{
				k=j;
			}
			if(k!=j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}	
	}
}