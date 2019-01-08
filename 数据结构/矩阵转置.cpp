#include<stdio.h>
int main()
{
	int a[4][4];
	int b[4][4]={0};
	int i,j,t=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j]=t++;
			printf("%d\t",a[i][j]);		
		}
		printf("\n");
	}
	//¾ØÕó×ªÖÃÌ×Â· 
	printf("\n\n×ªÖÃ£º\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			b[i][j]=a[j][i];
			printf("%d\t",b[i][j]);	
		}
		printf("\n");
	}
	return 0;
}