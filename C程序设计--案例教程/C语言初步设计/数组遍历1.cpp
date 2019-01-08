#include<stdio.h>
main()
{
	//输入二维数组套路！！ 
	int a[3][4],i,j,amax,sum=0;
	float ave;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);	
		}
	}
	//二维数组比较的小套路！！ 
	amax=a[0][0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			sum+=a[i][j];
			if(amax<a[i][j])
			{
				amax=a[i][j];
			}
		}
	}
	ave=sum/(3.0*4);
	
	//二维数组遍历套路！！！ 
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("max=%d,average=%.2f\n",amax,ave);
	
	return 0;
}
