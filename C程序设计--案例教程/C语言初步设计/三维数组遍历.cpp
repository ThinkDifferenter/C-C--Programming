#include<stdio.h>
main()
{
	//三维数组的遍历？？？？ 
	int i,j,k;
	int a[3][3][3]={1,2,3,4,5,6,7,8,9};
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				printf("%5d",a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
} 
