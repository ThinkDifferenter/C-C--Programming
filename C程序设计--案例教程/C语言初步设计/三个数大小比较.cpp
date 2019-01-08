#include<stdio.h>
main()
{
	int a,b,c ,min,max;
	printf("Please input a,b,c:");
	scanf("%d %d %d",&a,&b,&c);
	
	max=a;
	if(b>max)
	max=b;
	if(c>max)
	max=c;
	printf("the maxmum is: %d\n",max);
	
	min=a;	
	if(b<min)
	min=b;
	if(c<min)
	min=c;
	printf("the minmum is: %d\n",min);
	
	return 0;
	
	
	
}
