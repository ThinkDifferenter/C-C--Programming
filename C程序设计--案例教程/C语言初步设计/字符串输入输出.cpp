#include<stdio.h>
#include<string.h>
 
main()
{
	char str[80],c;
	int i,j;
	gets(str);//����һ���ַ��� 
	c=getchar();//���һ�����ַ��� 
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
