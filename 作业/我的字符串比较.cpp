#include<stdio.h>
int main()
{
	char str1[100],str2[100];
	int i=0,j;
	printf("请输入字符串一:\n");
	gets(str1);
	printf("请输入字符串二:\n");
	gets(str2);
	for(j=0;str1[j]!='\0';j++);
	while(str1[i]!='\0'||str2[i]!='\0')
	{
		if(str1[i]==str2[i])
		{
			i++;
		}
		else 
		{
			printf("str1[%d]-str2[%d]=%d\n",i,i,str1[i]-str2[i]);	
			break;
		}
	}
	if(i==j)
	{
		printf("两个字符串相等\n");
	}
	return 0;
}