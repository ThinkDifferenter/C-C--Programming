#include<stdio.h>
#include<stdlib.h>
struct date
{
	int day;
	int monht;
	int year;	
};
//����->(������������)�������.(ȡ��Ա�����)�����
//(������������)->ʹ�õĶ����ָ��
//(ȡ��Ա�����).ʹ�õĶ����ǽṹ���� 
int main()
{
	date today;
	date *Today=&today;
	Today->day=18;
	Today->monht=7;
	Today->year=2016;
	printf("show 1:\n");
	printf("Today is %d.%d.%d\n",today.year,today.monht,today.day);
	printf("show 2:\n");
	printf("Today is %d.%d.%d\n",Today-year,Today->monht,Today->day);
	return 0;	
}