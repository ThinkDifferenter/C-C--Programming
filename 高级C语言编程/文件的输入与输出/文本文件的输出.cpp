#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("text.txt","rt"))==NULL)
	{
		printf("cannot open the file!\n");
		exit(1);
	}

	while((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
	}
	printf("\n");
	fclose(fp);
	return 0;
}

