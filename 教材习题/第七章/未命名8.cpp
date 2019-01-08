#include<stdio.h>
int main()
{
	static int i,j,k;
	int a[10][10];
	a[0][1]=1;
	for(i=0;i<10;i++)
	{
		for(j=0;j<=i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}