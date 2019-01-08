#include<stdio.h>
int main()
{
	char a[]="jiangjun",b[20];
	int i;
	for(i=0;*(a+i)!='\0';i++)
	{
		*(b+i)=*(a+i);
	}
	*(b+i)='\0';
	
	printf("the string a is :%s\n",a);
	printf("the string b is :");
	for(i=0;*(b+i)!='\0';i++)
	{
		printf("%c",*(b+i));
	}
	printf("\n");
}