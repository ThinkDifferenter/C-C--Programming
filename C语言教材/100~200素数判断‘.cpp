#include<stdio.h>
#include<math.h>
int main()
{
	int m,k,i,n;
	for(m=101;m<=200;m+=2)
	{
		k=sqrt(m);
		for(i=2;i<=k;i++)
		{
			if(m%i==0) break;
		} 
		if(i>k)
		{
			printf("%dÊÇËØÊı\n",m);
		}
	}
	return 0;
} 