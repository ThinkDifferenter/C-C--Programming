#include<stdio.h>
int main()
{
	char str[20]="jiangjun";
	char *s;
	s="C program";
	for(int i=0;str[i]!='\0';i++)
	{
		printf("%c",str[i]);
	}
	printf("%c\n",str[19]);
	printf("\n");
	return 0;
} 