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
			s+=t1*h;//��������ۼӣ� 
			 
		}
	printf("���εĻ�������ǣ�%f��\n",s);
	
	return 0;
		
 } 
