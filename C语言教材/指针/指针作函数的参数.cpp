#include<stdio.h>
void average(double *p,int n);
void search(double (*p)[4],int n);//ע�⺯��ԭ�͵����� 
int main()
{
	double a[3][4]={{65,67,70,60},{80,87,90,81},{90,99,100,98}};
	average(*a,12);//�������1��������������һά���飬��ʼ��int *p=*a; 
	search(a,2);//�������2������һ��ָ��һ�е���ָ�룬��ʼ�� int (*p)[m]=a; 
	return 0;
} 
void average(double *p,int n)
{
	double *p_end;
	double sum=0,ave;
	p_end=p+n-1; 
	for(;p<p_end;p++)
	{
		sum+=*p;
	}
	ave=sum/n;
	printf("the average is %f\n",ave);
}
void search(double (*p)[4],int n)
{
	int i;
	printf("the score of NO.%d are :\n",n);
	for(i=0;i<4;i++)
	{
		printf("%.2f\t",*(*(p+n-1)+i));
	}
	printf("\n");
}