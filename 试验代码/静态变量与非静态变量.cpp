#include<stdio.h>
int i=3;
int increase1();
int increase2();
int increase3();
int main()
{
	printf("Groble:\n");
	printf("first:%d\n",increase3());
	printf("second:%d\n",increase3());
	printf("--------------------\n"); 
	printf("Static:\n");
	printf("first:%d\n",increase1());
	printf("second:%d\n",increase1());
	printf("--------------------\n");
	printf("Not static:\n");
	printf("first:%d\n",increase2());
	printf("second:%d\n",increase2());			
	return 0;	
}
int increase1()
{
	static int j=3;
	j++;
	return j;	
}
int increase2()
{
	int k=3;
	k++;
	return k;
}
int increase3()
{
	i++;
	return i;
}