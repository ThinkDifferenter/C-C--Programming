#include<stdio.h>
#define PI 3.1415926
int main()
{
	double r=1.5;
	double h=3.0;
	printf("Բ���ܳ�Ϊ:%.2f\n",2*PI*r); 
	printf("Բ�����Ϊ:%.2f\n",PI*r*r);
	printf("��ı����Ϊ:%.2f\n",4*PI*r*r);
	printf("������Ϊ:%.2f\n",4.0/3*PI*r*r*r);
	printf("Բ�������Ϊ:%.2f\n",2*PI*r*h);
	printf("Բ�������Ϊ:%.2f\n",PI*r*r*h);
	return 0; 
} 