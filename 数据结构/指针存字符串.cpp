#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *str;
	str=(char *)malloc(sizeof(char)*100+1);
	//str="jiangjun";
	printf("Please inout a string :\n");
	gets(str);
	puts(str);
	return 0;	
}