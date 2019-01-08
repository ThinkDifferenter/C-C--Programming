#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//模拟验证50人的班级至少两个人的生日相同的概率为97% 
int main()
{
	int a=0,bir[51],i,j,k,t;
	
	for(k=1;k<=100;k++)//百分比1~100% 
	{
		t=0;
		srand(time(00));
		for(i=1;i<=50;i++)//50位同学 
		{
			bir[i]=rand()%365+1;//随机产生50个生日 
		}
		for(i=1;i<=49;i++)
		{
			for(j=i+1;j<=50;j++)
			{
				if(bir[i]==bir[j])
				{
					t=1;
					a++;
					break;
				}
			}
			if(t==1)
			{
				break;
			}
		}
	}	
	printf("50人的班级有相同生日同学的概率为:%d%%\n",a);
	return 0;
}