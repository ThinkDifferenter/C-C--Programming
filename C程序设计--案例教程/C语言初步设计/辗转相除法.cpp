#include<stdio.h>
main()
{
	int m,n,r;
	printf("Please input m,n:");
	scanf("%d %d",&m,&n);
	
	//辗转相除发求解！！ 
	r=m%n;
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	printf("gcd=%d\n",n);
	
	return 0;
}

