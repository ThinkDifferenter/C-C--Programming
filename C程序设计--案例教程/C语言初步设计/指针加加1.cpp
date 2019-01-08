#include<stdio.h>
main()
{
	char a[]={0,1,2,3,4,5,6,7,8,9};
	char *p=a;//数组才能这样干！！!	 
	*p=a[0];
	
	printf("p =%d\n",*p);
	printf("*p=%p\n",p);
	printf("a[0]=%p\n",&a[0]);
	printf("*(p+1)=%p\n",(p+1));
	

	return 0;
}
