#include<stdio.h>
#include<stdlib.h>
int main()
{
//	int *p1=1;
//	double *p2=3.14;
	char *p3=(char *)malloc(sizeof(char)*100);
	p3="jiangjun";//only string is OK!
//	printf("%d\n",*p1);//cannot do this!
//	printf("%f\n",*p2);
	printf("%s\n",p3);
	free(p3);
	return 0;
}