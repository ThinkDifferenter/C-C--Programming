#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *p;
	int i;
	p=(char *)malloc(sizeof(char)*100+1);
	p="jiangjun";
	printf("the string is :");
	for(i=0;*(p+i)!='\0';i++)
	{
		printf("%c",*(p+i));
	} 
	printf("\n");
	for(i=0;*(p+i)!='\0';i++)
	{
		printf("第%d个字符的地址为%p\n",i+1,p+i);
	}
	return 0;
}