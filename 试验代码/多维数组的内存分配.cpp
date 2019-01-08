#include<stdio.h>
int main()
{
	int a[2][3];
	printf("%p\n",&a[0][2]);
	printf("%p\n",&a[1][0]);
	printf("&a[1][0]-&a[0][2]=%d\n",&a[1][0]-&a[0][2]);
	return 0;	
}