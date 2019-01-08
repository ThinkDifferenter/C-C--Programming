#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 256
typedef struct node
{
	char [MAXSIZE];
	int Length; 
}SeString;
//�󴮳�
int StrLength(char *s)
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}
//������
int String_Concat(char *s1,char *s2,char *s)
{
	int i=0,j=0,len1,len2;
	len1=StrLength(s1);
	len2=StrLength(s2);
	if(len1+len2>MAXSIZE-1)
	{
		return 0;
	}
	while(s1[j]!='\0')
	{
		s[i]=s1[j];
		i++;
		j++;		
	}
	j=0;
	while(s2[j]!='\0')
	{
		s[i]=s2[j];
		i++;
		j++;
	}
	s[i]='\0';
	return 1;
} 
//���Ӵ�
//��t����s�е�i���ַ���ʼ�ĳ���Ϊlen���Ӵ�������1<=i<=len 
int StrSub(char *t,char *s,int i,int len)
{
	int slen;
	slen=StrLength(s);
	if(i<1||i>slen||len<0||len>slen-1)
	{
		printf("varible error!\n");
		return 0;
	}	
	for(j=0;j<len;j++)
	{
		t[j]=s[i+j-1];
	}
	t[j]='\0';
	return 1;
} 
//���Ƚ�
int SreCmp(char *s1,char *s2)
{
	int i=0;
	while(s1[i]==s2[i]!='\0')
	{
		i++;
	}
	return s1[i]==s2[i];
} 
//�����Ӵ����Ӵ���λ�Ĺ��̳�Ϊģʽƥ�� 
// �򵥵�ģʽƥ���㷨   Brute_Force�㷨
int StrIndex_BF(char *s,char t)
{
	int i=1,j=1;//�������  
	while(i<=s[0])
	{
		if(s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2;
			j=1;
		}
	} 
	if(j>t[0])
	{
		return -1;
	}
} 

int main()
{
	return 0;
}