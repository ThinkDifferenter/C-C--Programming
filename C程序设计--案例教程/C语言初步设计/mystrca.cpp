#include<stdio.h>
int main()
{
	char str1[10],str2[20],str3[50];
	int i,j;
	printf("�������һ���ַ���:");
	gets(str1);
	printf("������ڶ����ַ���:");
	gets(str2);
	for(i=0;str1[i]!='\0';i++)
	{
		str3[i]=str1[i];
	}
	for(j=0,i=i;str2[j]!='\0';j++,i++)
	{
		str3[i]=str2[j];
	}
	str3[i]='\0';
	printf("���Ӻ���ַ���Ϊ:%s\n",str3);
	return 0;
	 
}