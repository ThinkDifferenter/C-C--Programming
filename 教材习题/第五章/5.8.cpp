#include<stdio.h>
int main()
{
	double i;
	double j;
	char ch;
	printf("请输入你所获得的利润:");
	scanf("%lf",&i);
	if(i<=100000)
	{
		ch='a';		
	}
	else if(i>=100000&&i<=200000)
	{
		ch='b';
	}
	else if(i>=200000&&i<=400000)
	{
		ch='c';
	}
	else if(i>=400000&&i<=600000)
	{
		ch='d';
	}
	else if(i>=600000&&i<=1000000)
	{
		ch='e';
	}
	
	else if(i>1000000)
	{
		ch='f';
	}
	switch(ch)
	{
		case 'a': j=i*0.1;break;
		case 'b':j=100000*0.1+(i-100000)*0.075;break;
		case 'c':j=100000*0.1+100000*0.075+(i-200000)*0.05;break;
		case 'd':j=100000*0.1+100000*0.075+200000*0.05+(i-400000)*0.03;break;
		case 'e':j=100000*0.1+100000*0.075+200000*0.05+300000*0.03+(i-600000)*0.015;break;
		case 'f':j=100000*0.1+100000*0.075+200000*0.05+300000*0.03+400000*0.015+(i-1000000)*0.01;break;
	}
	printf("我的奖金为:%f\n",j);
	return 0; 
	 
}