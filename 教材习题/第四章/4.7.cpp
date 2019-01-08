#include<stdio.h>
#define PI 3.1415926
int main()
{
	double r=1.5;
	double h=3.0;
	printf("圆的周长为:%.2f\n",2*PI*r); 
	printf("圆的面积为:%.2f\n",PI*r*r);
	printf("球的表面积为:%.2f\n",4*PI*r*r);
	printf("球的体积为:%.2f\n",4.0/3*PI*r*r*r);
	printf("圆柱的面积为:%.2f\n",2*PI*r*h);
	printf("圆柱的体积为:%.2f\n",PI*r*r*h);
	return 0; 
} 