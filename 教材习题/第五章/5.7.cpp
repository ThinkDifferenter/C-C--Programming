#include<stdio.h>
int main()
{
	int n,a[5];
	int i;
	printf("input a number (five):");
	scanf("%d",&n);
	for(i=0;i<5;i++)
	{
		a[i]=n%10;
		n=n/10;
		printf("%d\t",a[i]);
	}
	printf("\n\n");
	for(i=4;i>=0;i--)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}