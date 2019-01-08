#include<stdio.h>
void maopao(int *a,int n);
int main()
{
 	int a[4];
 	int i;
 	printf("inter four number:\n");
 	for(i=0;i<4;i++)
 	{
	 	scanf("%d",&a[i]);
	 }
	maopao(a,4);
	
	printf("arraged:\n");
	for(i=0;i<4;i++)
	{
		printf("%d\t",a[i]);
	} 	
	printf("\n");
	return 0;
}
void maopao(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=n-i-1;j>i;j--)//for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
}