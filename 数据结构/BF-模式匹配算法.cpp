#include<stdio.h>
#include<stdlib.h>
//BF�㷨����Brute��Force��Ƶ� 
int StrIndex_BF(char *s,char *t)
{
	int i=1,j=1;
	while(i<=s[0]&&j<=t[0])//�������λ�ô洢�ַ����ĳ��ȡ� 
	{
		if(s[i]==t[i])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2;//��������ȵ��ַ������ݡ� 
			j=1;
		}
	} //end while
	if(j>t[0])
	{
		return (i-t[0]);//ƥ��ɹ������ش洢λ�á� ����Ҫ��һ����Ϊ��һ���洢�ռ�û�д���ַ��� 
	}
	else
	{
		return -1;//ƥ��ʧ�ܡ� 
	}
}
int main()
{
	return 0;	
}