//��д����int f(char *s),�书���Ǽ���ִ�S�Ƿ����C�����﷨������Ϊ��
//��1���ִ�S�������ź������ŵĸ�����ȣ�
//��2���ִ���ǰ�����ʱ�������������������κ�ʱ�򲻳��������������������������
//�������������򣬺�����1�����򷵻�0.
#include<stdio.h>
#include<stdlib.h>
int f(char *s);
int main()
{
	char *s;
	int flag;
	s=(char *)malloc(sizeof(char)*100+1);
	printf("������һ��C���Դ���:\n");
	gets(s);
	flag=f(s);
	if(flag=1)
	{
		printf("����C�����﷨���򣬱���ͨ����\n");
	}
	else
	{
		printf("�������﷨���󣬱����쳣��\n");
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