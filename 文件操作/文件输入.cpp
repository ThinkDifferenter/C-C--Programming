#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("text.txt","wt"))==NULL)
	{
		printf("cannot open the file!\n");
		exit(1);
	}
	printf("Please input text:\n");
	while((ch=getchar())!='\n')
	{
		fputc(ch,fp);
	}
	fclose(fp);
	return 0;
}
