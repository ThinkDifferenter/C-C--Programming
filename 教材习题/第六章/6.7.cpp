#include<stdio.h>
int main()
{
	int i,m,s=0;
	for(m=6;m<1000;m++)
	{
		for(i=1;i<m;i++)
		{
			if(m%i==0)
			{
				s+=i;
			}
		}
		if(s==m)
		{
			printf("%d\t",m);	
		}
	}
	return 0;
}