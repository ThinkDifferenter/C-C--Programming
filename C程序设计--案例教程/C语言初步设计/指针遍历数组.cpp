#include<stdio.h>
main()
{
	char a[]={0,1,2,3,4,5,6,7,8,9,-1};
	char *p=a;
	char i;
	
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		printf("%d\n",a[i]);
	}
	for(p=a;*p!=-1;*p++)
	{
		printf("%d\n",*p);
	}
	while(*p!=-1)
	{
		printf("%d\n",*p++);
	}
	
	return 0;

}
