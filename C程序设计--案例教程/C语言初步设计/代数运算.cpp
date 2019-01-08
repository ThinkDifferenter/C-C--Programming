#include<stdio.h>
main()
{
	double i,s=0,n;
	
	printf("Please input n:");
	scanf("%lf",&n);
	
	for(i=1;i<=n;i++)
		s+=(1/i)-1/(i+1);
	
	printf("the result is %f\n",s);
	
	return 0;
	
}
