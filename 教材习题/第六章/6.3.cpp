#include<stdio.h>
#include<math.h>
int setnum(int a,int n);
int main()
{
	int a,n;
	long long sum=0;
	printf("Please input a,n:");
	scanf("%d %d",&a,&n);
	for(;n>0;n--)
	{
		sum+=setnum(a,n);
	}
	printf("the sum is %ld\n",sum);
	return 0;
}
int setnum(int a,int n)
{
	int i,j=a;
	for(i=1;i<n;i++)
	{
		j+=a*pow(10,i);	
	}
	return j;
}