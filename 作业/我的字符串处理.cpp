#include<stdio.h>
char mygets(char *str);
void myputs(char *str);
void mystrcat(char str1[],char str2[]);
char mystrcpy(char str1[],char str2[]);
char mystrncpy(char str1[],char str2[],int n);
int mystrcmp(char str1[],char str2[]);
int mystrlen(char str[]);
void mystrlwr(char str[]);
void mystrupr(char str[]);
int main()
{
	
	
}
void myputs(char *str)
{
	printf("%s",str);
}
char mygets(char *str)
{
	char ch;
	while(ch!='\n')
	{
		scanf("%c",ch);
	}
	return *str;
}
void mystrcat(char str1[],char str2[])
{
	char str3[100];
	int i,j;
	for(i=0;str1[i]!='\0';i++)
	{
		str3[i]=str1[i];
	}
	for(j=0,i=i;str2[j]!='\0';j++,i++)
	{
		str3[i]=str2[j];
	}
	str3[i]='\0';
	printf("连接后的字符串为:%s\n",str3);
}
char mystrcpy(char str1[],char str2[])
{
	int i;
	for(i=0;str2[i]!='\0';i++)
	{
		str1[i]=str2[i];
	}
	return *str1;
}
char mystrncpy(char str1[],char str2[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		str1[i]=str2[i];
	}
	return *str1;
}
int mystrcmp(char str1[],char str2[])
{
	int i;
	for(i=0;str1[i]!='\0'||str2[i]!='\0';i++)
	{
		if(str1[i]==str2[i])
		{
			return 0;
		}
		else if(str1[i]>str2[i])
		{
			return 1;
			break;	
		}
		else
		{
			return -1;
			break;
		}
	}
}

int mystrlen(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++);
	return i+1;
}

void mystrlwr(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=str[i]+32;
	}
	printf("%s\n",str);
}

void mystrupr(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=str[i]-32;
	}
	printf("%s\n",str);
}