#include<stdio.h>
int main()
{
	int i,j,max;
 	static int a[3][5]={{1,2,3,4,5},{2,3,4,5,7,1},{9,0,7,8,10}};
	
	max=a[0][0];
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
			}
		}
	}
	printf("the max is %d\n",max);
	return 0;
}