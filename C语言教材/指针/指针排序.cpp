#include<stdio.h>
void swap(int *p1,int *p2);
void exchange(int *q1,int *q1,int *q3);
int main()
{
	int a,b,c;
	int *p1=&a,*p2=&b,*p3=&c;
	printf("Please inter a,b,c:");
	scanf("%d %d %d",&a,&b,&c);
	exchange(p1,p2,p3);	
	printf("%d %d %d\n",a,b,c);
	return 0;	
}
void swap(int *p1,int *p2)
{
	int tmp;
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}
void exchange(int *q1,int *q2,int *q3)
{
	if(*q1<*q2)   swap(q1,q2);
	if(*q1<*q3)   swap(q1,q3);
	if(*q2<*q3)   swap(q2,q3);
}