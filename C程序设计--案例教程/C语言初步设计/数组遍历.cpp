#include<stdio.h>
main()
{
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int b[][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int i,j;
	printf("arry a:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("array b:\n");
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		{
			printf("%4d",b[i][j]);
		}
		printf("\n");
	}

	
	return 0;

}
