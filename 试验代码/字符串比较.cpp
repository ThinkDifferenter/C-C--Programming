#include<stdio.h>
#include<string.h>
int main()
{
	char a[]="jiangjun";
	char b[]="Jiangjun";
	if(strcmp(a,b))
	{
		printf("you are bigger!\n");
	}
	printf("%d\n",strcmp(a,b));
	printf("%d\n",'j'-'J');
	return 0;
}