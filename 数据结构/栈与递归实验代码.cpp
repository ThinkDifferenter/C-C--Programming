#include<stdio.h>
#include<stdlib.h>
//�������Ԫ��֮�ͺ���
int sum(int a[],int l,int h)//l for low,h for high 
{
	int result;
	if(l==h)
	{
		result=a[l];	
	}
	else
	{
		result=(sum(a,l,h-1)+a[h]);
	}
	return result;
} 
//�ݹ��㷨���ȫ������
void Swape(int a[],int i,int j)
{
	 int t;
	 t=a[i];
	 a[i]=a[j];
	 a[j]=t;	
} 
void Perm(int list[],int k,int m)
{
	int i;
	if(k==m)
	{
		for(i=0;i<=m;i++)
		{
			printf("%d",list[i]);
		} 
		printf("\n");
	}
	else
	{
		for(i=k;i<=m;i++)
		{
			Swape(list,k,i);
			Perm(list,k+1,m);
			Swape(list,k,i); 
		}
	}
}

//�ݹ��㷨�����ַ���
void ConverseStr(char *str,int start,int end)
{
	char t;
	if(end-start<1)
	{
		return ;
	}
	else
	{
		t=str[start];
		str[start]=str[end];
		str[end]=t;//������Ӧλ�ϵ��ַ�!!! 
		ConverseStr(str,start+1,end-1);
	}
} 

//�𳵽�վ����ݹ��㷨
//��ĳһʱ��վ̨�����i�л𳵣�վ̨����j�л�
//��1��վ̨��ŷ����һ�л���վ̨
//��2��վ̨����ϵĻ𳵳�վ 
//���ÿһ�β��������� 
int Train_into_PlantForm(int i,int j)
{
	if(i==0)//վ��û�л� 
	{
		return 1;
	} 
	else if(j==0)//վ��û�л�  
	{
		return Train_into_PlantForm(i-1,1);
	}
	else
	{
		return Train_into_PlantForm(i-1,j+1)+Train_into_PlantForm(i,j-1);
	} 
	
} 
 
int main()
{
	return 0;
} 