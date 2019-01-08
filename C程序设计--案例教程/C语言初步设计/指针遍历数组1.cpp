#include<stdio.h>
main()
{
	char a[]={0,1,2,3,4,5,6,7,8,9,-1};
	char *p=a;
	char i=0;
	
	while(*p!=-1)
	{
		printf("%d""\n",*p++);//一样的输出效果！！！！ 
	}

	
	return 0;
}
