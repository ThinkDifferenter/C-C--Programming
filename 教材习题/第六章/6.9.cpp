#include<stdio.h>
int main()
{
	double high=100,s=0;
	int cnt;
	for(cnt=0;cnt<10;cnt++)
	{
		s+=high;
		high=high/2.0;	
	}
	printf("第十次反弹的高度为:%.2f\n",high);
	printf("一共经过的路程为:%.2f\n",s);
	return 0;
}