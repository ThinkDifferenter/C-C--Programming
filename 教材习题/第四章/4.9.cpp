#include<stdio.h>
int main()
{
	double c;
	printf("请输入华氏温度:");
	scanf("%lf",&c);
	printf("输出温度为:%.2f\n",5.0/9*(c-32));
	return 0;
}