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
	printf("��ʮ�η����ĸ߶�Ϊ:%.2f\n",high);
	printf("һ��������·��Ϊ:%.2f\n",s);
	return 0;
}