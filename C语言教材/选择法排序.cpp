#include<stdio.h>
void sort(int a[],int n);
int main()
{
	int a[10],i;
	printf("Enter the array:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Show array:(before arrange)\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	
	sort(a,10);
	
	printf("Show array(later arrange):\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
} 
void sort(int a[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
			{
				k=j;
			}
			t=a[k];
			a[k]=a[i];
			a[i]=t;
		} 
	}
}