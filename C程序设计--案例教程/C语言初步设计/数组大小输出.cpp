#include<stdio.h>
main()
{
	int a[4][4]={{1,4,3,2},{8,6,5,7},{3,7,2,5},{4,8,6,1}};
	int i,j,k;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][i]<a[j][j])
			{
				k=a[i][i];
				a[i][i]=a[j][j];
				a[j][j]=k;
			}
		}
	}
	for(i=0;i<4;i++)
	{
		printf("%d,\n",a[0][i]);
	}
	return 0;

}
