#include<stdio.h>
void mystrcpy(char *to,char *from);
int main()
{
	char a[]="I am a student";
	char b[]="you are a teacher";
	printf("string a :%s\n",a);
	printf("string b :%s\n",b);
	printf("copy string a to string b:");
	mystrcpy(b,a);
	printf("\nstring a :%s\n",a);
	printf("string b :%s\n",b); 
	return 0;	
} 
void mystrcpy(char *to,char *from)
{
	int i;
	for(i=0;*(from+i)!='\0';i++)
	{
		*(to+i)=*(from+i);
	}
	*(to+i)='\0';
}