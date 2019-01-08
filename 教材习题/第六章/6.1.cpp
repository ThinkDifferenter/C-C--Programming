#include<stdio.h>
int main()
{
	int n,m,t=1;
	int t1,t2;
	printf("Please input m,n:");
	scanf("%d %d",&m,&n);
	
	t1=m;
	t2=n;	
	while(t!=0)
	{
		t=m%n;
		m=n;
		n=t;
	}
	printf("m,n的最大公倍数为:%d\n",t1*t2/m);
	printf("m,n的最小公约数为:%d\n",m); 
	return 0;
}