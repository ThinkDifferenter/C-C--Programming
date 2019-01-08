#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	char a[1000];
	int i=0;
	if((fp=fopen("text.txt","rt"))==NULL)
	{
		printf("canot open the file!\n");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
		a[i++]=ch;
	}
	a[i+1]='\n';
	printf("\n");
	printf("\n\nshow text by array:(way 1)\n");
	for(i=0;a[i]!='\n';i++)
	{
		printf("%c",a[i]);
	}
	printf("\n\nshow text by array:(way 2)\n");
	printf("%s\n",a);
	printf("\n");
	fclose(fp);
	return 0;
}