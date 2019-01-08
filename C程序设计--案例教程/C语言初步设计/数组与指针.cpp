#include<stdio.h>
main()
{
	int a[6]={0,1,2,3,4,5,};
	int *p=a;//指向数组的指针！！！ 
	
	printf("%d\n",*p);
	printf("%d\n",a[0]);
	
	return 0;
}
