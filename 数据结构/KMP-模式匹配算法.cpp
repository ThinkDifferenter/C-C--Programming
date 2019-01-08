#include<stdio.h>
#include<stdlib.h>
//KMPģʽƥ���㷨�ǿ�Ŭ˹��Knuth����Ī��˹��MOrris���������أ�Prattle��ͬʱ��Ƶ� 
//���BFģʽƥ���㷨��KMPģʽƥ���㷨���õ�������ģʽ�������ıȽ���Ϣ��û��ֱ�ӻ��ݣ�
//����ͨ��next �����ж�ģʽtӦ�ûص��������ֲ���ģʽt��ȵ� 
int StrIndex_KMP(char *s,char *t,int pos)
//�Ӵ�s�ĵ�pos���ַ���ʼ���״��봮t��ģʽ����ȵ��Ӵ� 
{
	int i=pos,j=1;
	while(i<=s[0]&&j<=t[0])
	{
		if(j==0||s[i]==t[j])
		{
			i++;
			j++; 
		}
		else
		{
			j=next[j];
		}
	}//end while
	if(j>t[0])
	{
		return (i-t[0]);
	}
	else
	{
		return -1;
	}
}
//next�������ģʽtҪ�������ϻ����ľ��롣 
void GetNext(char *t,int next[])
//��ģʽt��nextֵ������next�����У��ַ������ȱ�����t[0]�С� 
{
	int i=1,j=0;
	next[1]=0;
	while(i<t[0])
	{
		if(j==0||t[i]==t[j])
		{
			++i;
			++j;
			next[i]=j;
		}	
		else
		{
			j=next[j];
		}
	}//end while
}
//�ݹ��㷨��nextֵ
void GetNext_Recursion(char *t,int next[],int L)
//��ģʽ��t��nextֵ������next�����У�����tΪģʽ����LΪģʽ���ĳ��ȣ�t[0]����
//�㷨����ʱ���ַ���t��next����ֵ������next[]�У����±�1��ʼ�洢�� 
{
	if(L==1)
	{
		next[1]=0;
		return ;
	}	
	GetNext_Recursion(t,next,L-1);
	int k=next[L-1];
	while(1)
	{
		if(t[k]==t[L-1])
		{
			next[L]=k+1;
			return ;
		}
		k=next[k];
		if(k==0)
		{
			next[L]=1;
			return ;
		}
	}
} 
int main()
{
	return 0; 
} 