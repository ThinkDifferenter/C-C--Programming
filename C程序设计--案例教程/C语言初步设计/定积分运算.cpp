#include<stdio.h>
#include<math.h>
main()
{
	//���η��󶨻��ֳ�����ƣ�
	int i,n=1000;
	double a,b,h,t1,t2,s,x;
	
	printf("���������������a,b:");
	scanf("%lf %lf",&a,&b);
	
	h=(b-a)/n;
	for(s=0,i=1;i<=n;i++)
		{
			x=a+(i-1)*h;
			t1=exp(-x*x/2);//exp�������ã�
			t2=exp(-(x+h)*(x+h)/2);
			s+=(t1+t2)*h/2;
		}
	printf("���η���û���ֵ�ǣ�%f��\n",s);
	
	return 0;
}
