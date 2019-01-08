#include<stdio.h>
main()
{
	//1*3+3*5+5*7+.....+ги2n-1)*(2n+1) 
	long i,s=0,n;
	
	printf("Please input n:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		s+=(2*i-1)*(2*i+1);
	
	printf("the result is %d\n",s);
	
	return 0;
}
