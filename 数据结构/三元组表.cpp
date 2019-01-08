#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 256
typedef struct node
{
	int i,j;//����Ԫ�����ڵ��к��� 
	int v;	//����Ԫ�ص�ֵ 
}triple;
typedef struct Node
{
	triple date[MAXSIZE];//��Ԫ�������Ԫ�صĸ�������ԭ���ʵ����������ʽ�� 
	int  m,n,t;//���������������� 
}tripletable;

//��Ԫ���ת��
//�����ң�˳�Ŵ� ����A�е�ÿһ��col��1<=col<=n��,ͨ����ͷ��βɨ����Ԫ��a.date���ҳ������к�
//����col����Щ��Ԫ�飬�����ǵ��кź��кŻ��������η���b.date�У����ɵõ�B�İ������ȵ�ѹ���洢��ʾ 
tripletable transmatrix(tripletable a)
{
	tripletable b;
	int p,q,col;
	b.m=a.n;
	b.n=a.m;
	b.t=a.t;
	if(b.t)
	{
		q=0;
		for(col=1;col<=a.n;col++)
		{
			for(p=0;p<a.t;p++)
			{
				if(a.date[p].j==col)
				{
					b.date[q].i=col;
					b.date[q].j=a.date[p].i;
					b.date[q].v=a.date[p].v;
					q++;
				}//end if
			}//end in for
		}//end out for
	}//end if
	return b;
}
//˳���ң����Ŵ�
//��Aɨ��һ�Σ���A�ڶ����ṩ���к�һ��ȷ��λ��װ��B����Ԫ����У�
//һ��ɨ����ȷ����Ԫ���λ�ù�ϵ������ɨ����λ�ù�ϵװ����Ԫ�顣 
//num[j]��ʾAj�����j����һ������Ԫ�ظ�����pot[j]��ʾ����A�е�J����һ������Ԫ����B��Ӧ��ŵ�λ�� 
tripletable fasttranstri(tripletable a)
{
	tripletable b;
	int p,q,col,k;
	int num[a.n+1];
	int pot[a.n+1];
	b.m=a.n;
	b.n=a.m;
	b.t=a.t;
	if(b.t)
	{
		for(col=1;col<=a.n;++col)
		{
			num[col]=0;
		}
		for(k=0;k<a.t;++k)
		{
			++num[a.date[k].j];
		}
		pot[1]=0;
		for(col=2;col<=a.n;++col)
		{
			pot[col]=pot[col-1]+num[col-1];
		} 
		for(p=0;p<a.t;++p)
		{
			col=a.date[p].j;
			q=pot[col];
 
			++pot[col];
		}
	}
	return b;
} 