#include<stdio.h>
int max(int i,int j);

int main()
{
	int (*p)(int i,int j);//����һ��ָ������ָ�� 
	p=max;//��������Ӧ�ĵ�ַ���Ǻ�������ڵ�ַ 
	int a,b,c;
	printf("inter a,b:");
	scanf("%d %d %d",&a,&b,&c);
	c=(*p)(a,b);//ͨ��ָ����ú��� 
	printf("the max of a,b is %d\n",c);
	return 0;	
} 
int max(int i,int j)
{
	int k;
	if(i>j)
	{
		return i;
	}
	else
	{
		return j;
	}
}