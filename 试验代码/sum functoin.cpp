#include<stdio.h>
int main()
{
	int a[3];
	int i;
	a[0]=0;
	printf("inter two number:\n");
	for(i=1;i<3;i++)
	{
		scanf("%d",&a[i]);
		a[0]+=a[i];	
	}
	printf("the sum is %d\n",a[0]);
	return 0;
}