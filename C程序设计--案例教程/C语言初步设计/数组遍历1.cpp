#include<stdio.h>
main()
{
	//�����ά������·���� 
	int a[3][4],i,j,amax,sum=0;
	float ave;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);	
		}
	}
	//��ά����Ƚϵ�С��·���� 
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
	
	//��ά���������·������ 
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
