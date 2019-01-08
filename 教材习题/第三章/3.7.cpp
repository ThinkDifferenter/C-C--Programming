#include<stdio.h>
int main()
{
	char str[100];
	int i;
	printf("input text :");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=str[i]+4;
	}
	printf("the screat text is %s\n",str);
	return 0;
}