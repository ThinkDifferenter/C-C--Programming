#include<stdio.h>
#include<string.h>
 
main()
{
	char str[80],c;
	int i,j;
	gets(str);//输入一个字符串 
	c=getchar();//输出一个子字符串 
	j=0;
	for(i=0;str[i!='\0'];i++)
	{
		if(str[i]!=c)
		{
			str[j]=str[i];
			j++;
		}
	}
	str[j]!='\0';
	puts(str);		
		
}
