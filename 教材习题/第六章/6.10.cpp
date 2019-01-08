#include<stdio.h>
int main()
{
	int total=0,day,n=1;
	for(day=9;day>0;day--)
	{
		total+=n*2+1;
		n=(n+1)*2;
	}
	printf("the total is %d\n",total);
	return 0;
}