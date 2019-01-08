#include<stdio.h>
main()
{
	int m,n,r=1;
	int i,j;
	printf("Please input m,n:");
	scanf("%d %d",&m,&n);
	i=m,j=n;
	//辗转相除法求解！！ 
	r=m%n;
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	printf("最大公约数:%d\n",n);
	printf("最小公倍数:%d\n",(i*j)/n);
	return 0;
}
