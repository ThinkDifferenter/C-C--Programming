#include<stdio.h>
main()
{
	int a,b,c ,min,max;
	printf("Please input a,b,c:");
	scanf("%d %d %d",&a,&b,&c);
	
	//maxmum
	if(a>b)
	{
		if(a>c)
		{
			printf("the maxmum is %d\n",a);
		}
		else 
		{
			printf("the maxmum is %d\n",c);
		}

	}
	else
	{
		if(b>c)
		{
			printf("the maxmum is %d\n",b);
		}
		else
		{
			printf("the maxmum is %d\n",c);
		}
	}


	//minmum
		if(a<b)
	{
		if(a<c)
		{
			printf("the minmum is %d\n",a);
		}
		else 
		{
			printf("the maxmin is %d\n",c);
		}

	}
	else
	{
		if(b<c)
		{
			printf("the minmum is %d\n",b);
		}
		else
		{
			printf("the minmum is %d\n",c);
		}
	}
	
	return 0;

	
}
