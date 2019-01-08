#include<stdlib.h>
#include<stdio.h>
int main()
{
	char *str;
	int i,cha=0,spa=0,num=0,oth=0;
	str=(char *)malloc(sizeof(char)*100+1);
	printf("Please input a string :\n");
	gets(str);
	for(i=0;*(str+i)!='\0';i++)
	{
		if(*(str+i)>='a'&&*(str+i)<='z'||*(str+i)>='A'&&*(str+i)<='Z')
		{
			cha++;
		}
		else if(*(str+i)==' ')
		{
			spa++;
		}
		else if(*(str+i)>='0'&&*(str+i)<='9')
		{
			num++;
		}
		else
		{
			oth++;
		}
	}
	printf("英文字母有%d个\n",cha);
	printf("空格有%d个\n",spa);
	printf("数字有%d个\n",num);
	printf("其他字符有%d个\n",oth);
	return 0; 
	
}