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
	printf("Ӣ����ĸ��%d��\n",cha);
	printf("�ո���%d��\n",spa);
	printf("������%d��\n",num);
	printf("�����ַ���%d��\n",oth);
	return 0; 
	
}