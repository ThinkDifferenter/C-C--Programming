#include <math.h> 
#include <stdio.h>
#define f(x) x*x+5*x+8   
double calc(double *a,double *b,double e,int *n) 
{ 	double x1,x2,s; 
	if(fabs(*b-*a)<=e) 
	{
		s=f((*b+*a)/2);
	}
	else 
	{  	
		x1=*b-0.618*(*b-*a); 
		x2=*a+0.618*(*b-*a); 
	}
	if(f(x1)>f(x2))
	{
		*a=x1;	
	} 	 
	else
	{
		*b=x2; 
		*n=*n+1; 
		s=calc(a,b,e,n); 
	} 
	return s; 
} 
int main() 
{ 	double s,a,b,e; 
	int n=0; 
	printf(" ‰»Î«¯º‰:");
	scanf("%lf %lf %lf",&a,&b,&e);    
	s=calc(&a,&b,e,&n);     
	printf("a=%lf,b=%lf,s=%lf,n=%d\n",a,b,s,n); 
	return 0;
} 