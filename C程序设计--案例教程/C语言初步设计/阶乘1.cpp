#include<stdio.h>
main()
{
	int i,n;
	long t=1;
	float s=1;
	
	printf("Please input n:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		{
			t=t*i;
			s=s+1.0/t;
		}
	printf("s=%8.6f\n",s);
		
	return 0;
	
}
