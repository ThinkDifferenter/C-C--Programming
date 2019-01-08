#include<stdio.h>
int main()
{
	char str[100];
	int i,flag=1,cnt=0;
	printf("please input a string:");
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			flag=1;
		}
		else if(flag==1)
		{
			flag=0;
			cnt++;
		}
	}
	printf("there are %d character in the string\n",cnt);
	return 0;
}