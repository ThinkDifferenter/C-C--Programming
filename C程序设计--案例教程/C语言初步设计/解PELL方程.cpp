#include<stdio.h>
#include<math.h>

main()
{
	int n,m,t;
	long a,x,y;
	
	printf("��PELL���̣�x^2-ny^2=1.\n");
	printf("�������ƽ�������� n��");
	scanf("%d",&n);
	
	m=sqrt(n);
	if(m*m==n)
	{
		printf("n Ϊƽ�����������������⣡\n");
		return 0;
	}
	printf("��PELL���̣�x^2-ny^2=1\n",n);
	for(y=1;y<=1000;y++)
	{
		a=n*y*y;
		x=sqrt(a+1);
		if(x*x==a+1)
		{
			printf("���̵Ļ�����Ϊ��");
			printf("x=%ld,y=%ld\n",x,y);
			break; 
		}
	}
	return 0;
}
