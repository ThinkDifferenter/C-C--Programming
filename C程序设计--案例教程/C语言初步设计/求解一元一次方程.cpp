#include<stdio.h>
#include<math.h>
main()
{
	float a,b,c,d,a2,x1,x2;
	printf("Please input a,b,c:");
	scanf("%f %f %f",&a,&b,&c);
	
	if (a==0)
	{
		x1=-c/b;
		printf("root=%f\n",x1);
	}
	else
	{
		d=b*b-4*a*c;
		a2=2*a;
		x1=-b/a2;
		if(d>=0)
		{
			x2==sqrt(d)/a2;
			printf("real root:\n");
			printf("root1=%f,root2=%f\n",x1+x2,x1-x2);
		}
		else
		{
			x2=sqrt(-d)/a2;
			printf("complex root:\n");
			printf("rooot1=%f+%fi\n",x1,x2);
			printf("root22=%f-%fi\n",x1,x2);
			
		}
	}
	
}
