#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	int x1,x2,deta=0;
	printf("inter a,b,c for function:");
	scanf("%d %d %d",&a,&b,&c);
	deta=b*b-4*a*c;
	if(deta>0)
	{
		x1=(-b+sqrt(deta))/2*a;
		x2=(-b-sqrt(deta))/2*a;
		printf("���������������ͬ�ĸ�:x1=%d x2=%d",x1,x2);
	}
	else if(deta=0)
	{
		x1=x2=-b/2*a;
		printf("���������������ͬ�ĸ�:x1=x2=%d",x1);
	}
	else
	{
		deta=-deta;
		x1=(-b+sqrt(deta))/2*a;
		x2=(-b-sqrt(deta))/2*a;
		printf("�������û��ʵ����");
		printf("������̵�����������Ϊ:x1=%di x2=%di",x1,x2);
	}
	return 0; 
}