#include<stdio.h>
int main()
{
	int a[10]={98,15,54,23,16,31,90,15,45,67};
	int i,j=0;
	for(i=0;i<10;i++)
	{
		a[j--]=a[i];	
	}
	return 0;
} 