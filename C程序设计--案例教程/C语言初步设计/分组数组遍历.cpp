#include<stdio.h>
main()
{
	int a[4][4]={{1,4,3,2},{8,6,5,7},{3,7,2,5},{4,8,6,1}};
	int i,j,k;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
