#include<stdio.h>
#include<stdlib.h>
struct date
{
	int day;
	int monht;
	int year;	
};
//区别->(间接引用运算符)运算符合.(取成员运算符)运算符
//(间接引用运算符)->使用的对象的指针
//(取成员运算符).使用的对象是结构变量 
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