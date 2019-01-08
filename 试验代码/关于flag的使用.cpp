#include<stdio.h>
int main()
{
	char a[100];
	int word=0,flag=0,i;
	printf("input a string :\n");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==' ')
		{
			flag=0;
		}
		else if(flag==0)
		{
			word++;
			flag=1;
		}
	}
	printf("the input string has %d word\n",word);
	return 0;
}