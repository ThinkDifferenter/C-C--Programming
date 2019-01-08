//编写函数int f(char *s),其功能是检查字串S是否符合C语言语法，规则为：
//（1）字串S的左括号和右括号的个数相等；
//（2）字串从前向后检查时，遇到的右括号数在任何时候不超过或低于已遇到的左括号数，
//若满足上述规则，函数返1，否则返回0.
#include<stdio.h>
#include<stdlib.h>
int f(char *s);
int main()
{
	char *s;
	int flag;
	s=(char *)malloc(sizeof(char)*100+1);
	printf("请输入一段C语言代码:\n");
	gets(s);
	flag=f(s);
	if(flag=1)
	{
		printf("满足C语言语法规则，编译通过！\n");
	}
	else
	{
		printf("代码有语法错误，编译异常！\n");
	}
	return 0;
}
int f(char *s)
{
	int cnt1=0,cnt2=0;
	int flag;
	while(*s++!='\0')
	{
		if(*s=='(')
		{
			cnt1++;
		}
		if(*s==')')
		{
			cnt2++;
		}
	}
	if(cnt1<=cnt2)
	{
		flag=1;
	}
	else
	{
		flag=0;
	}
	return flag;
}