#include<stdio.h>
int main()
{
	char str1[100];
	char str2[100];
	printf("inter string:(by gets)");
	gets(str2);//end of enter
	printf("string2=");
	puts(str2);
	printf("inter string:(by scanf)");
	scanf("%s",str1);//end of space
	printf("string1=%s\n",str1); 
	return 0; 
} 