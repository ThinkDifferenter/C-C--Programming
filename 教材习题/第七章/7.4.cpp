#include<stdio.h>
int main()
{
	int a[4]={1,4,5};
	int i,t;
	printf("input a number:");
	scanf("%d",&a[3]);
	for(i=0;i<4;i++)
	{
		if(a[i]>=a[3])
		{
			t=a[i];
			a[i]=a[3];
			a[3]=t;	
		}
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}