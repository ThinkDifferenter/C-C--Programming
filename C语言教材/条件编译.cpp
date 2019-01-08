#include<stdio.h>
#define LEFTER 1
int main()
{
	char str[20]=" C Language";
	int i=0;
	while(str[i]!='\0')
	{
		i++;
		#if LEFTER
		if(str[i]>='a'&&str[i]<'z')
		{
			str[i]-=32;
		}
		#else
		if(str[i]>='A'&&str[i]<='Z')
		{
			str[i]+=32;
		}
		#endif
		printf("%c",str[i]);
	}
	printf("\n");	
}