#include<stdio.h>
int main()
{
	int a[10],i=0,max=0;
	printf("inter ten numnber:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);	
	}
	max=a[0];
	for(i=0;i<10;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	printf("the max of ten number is %d\n",max);
	return 0;
}