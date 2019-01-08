#include<stdio.h>
main()
{
	//1*3+3*5+5*7+.....+ги2n-1)*(2n+1) 
	long i,s=0,n;

	printf("Please input n:");
	scanf("%d",&n);
	
	for(i=1;i<=2*n-1;i+2)
		s+=i*(i+2);
	printf("the result is %d\n",s);
	
	return 0;
		
}
