#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdarg.h>

int sum(int n,...)
{
	int i , sum = 0;
	va_list vap;
	va_start(vap , n);     //ָ��ɱ�������еĵ�һ������
	for(i = 0 ; i < n ; ++i)
		sum += va_arg(vap , int);     //ȡ���ɱ�������еĲ��������޸Ĳ���ָ��vapʹ��������ָ�������һ������
	va_end(vap);    //��ָ��vap��ֵΪ0
	return sum;
}
int main(void)
{
	int m = sum(30,45,89,72);
	printf("%d\n",m);
	//cout<<m<<endl;
	return 0;
}