#include<stdio.h>
#include<math.h>

main()
{
	int n,m,t;
	long a,x,y;
	
	printf("解PELL方程：x^2-ny^2=1.\n");
	printf("请输入非平方正整数 n：");
	scanf("%d",&n);
	
	m=sqrt(n);
	if(m*m==n)
	{
		printf("n 为平方数，方程无正数解！\n");
		return 0;
	}
	printf("解PELL方程：x^2-ny^2=1\n",n);
	for(y=1;y<=1000;y++)
	{
		a=n*y*y;
		x=sqrt(a+1);
		if(x*x==a+1)
		{
			printf("方程的基本解为：");
			printf("x=%ld,y=%ld\n",x,y);
			break; 
		}
	}
	return 0;
}
