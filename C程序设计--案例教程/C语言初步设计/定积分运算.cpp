#include<stdio.h>
#include<math.h>
main()
{
	//矩形法求定积分程序设计！
	int i,n=1000;
	double a,b,h,t1,t2,s,x;
	
	printf("请输入积分上下限a,b:");
	scanf("%lf %lf",&a,&b);
	
	h=(b-a)/n;
	for(s=0,i=1;i<=n;i++)
		{
			x=a+(i-1)*h;
			t1=exp(-x*x/2);//exp函数调用！
			t2=exp(-(x+h)*(x+h)/2);
			s+=(t1+t2)*h/2;
		}
	printf("梯形法算得积分值是：%f。\n",s);
	
	return 0;
}
