#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp,fp1,*fp2;
	char ch;
	
	if((fp=fopen("text.txt","wt"))==NULL)
	{
		printf("cannot open the file!\n");
		exit(1);
	}
	if((fp1=fopen("text1.txt","rt"))==NULL)
	{
		printf("cannot open the file!\n");
		exit(1);
	}
	if((fp2=fopen("text2.txt","rt"))==NULL)
	{
		printf("cannot open the file!\n");
		exit(1);
	}
	
	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp);
	}	
	while((ch=fgetc(fp2))!=EOF)
	{
		fputc(ch,fp);
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	printf("文件合并完毕！\n");
	return 0; 
} 