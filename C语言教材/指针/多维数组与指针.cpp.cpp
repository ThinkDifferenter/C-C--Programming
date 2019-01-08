#include<stdio.h>
int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int i,j;
	printf("show array:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("%p\t%p\n",a,*a);
	printf("%p\t%p\n",a[0],*(a+0));	
	printf("%p\t%p\n",&a[0],&a[0][0]);
	printf("%p\t%p\n",&a[1],a+1);
	printf("%p\t%p\n",&a[1][0],*(a+1)+0);
	printf("%p\t%p\n",a[2],*(a+2));
	printf("%p\t%p\n",&a[2],a+2);
	printf("%p\t%p\n",a,&a[0][0]);
	printf("%p\t%p\n",&a[0][3],&a[1][0]);
	printf("%d\t%d\n",**a,a[0][0]);
	printf("%d\t%d\n",*a[0],a[0][0]);
	printf("%d\t%d\n",*(*(a+0)+0),a[0][0]);
	return 0;
}