#include<stdio.h>
main()
{
	//1*2+2*3+3*4+......+n*(n+1) 
	long i,s=0,n;
	printf("Please input n:");
	scanf("%d",&n);
	
	
	for(i=1;i<=n;i++)
		s+=i*(i+1);//s=s+i*(i+1)
	printf("the result is %d\n",s);
	
	return 0;
	
}
