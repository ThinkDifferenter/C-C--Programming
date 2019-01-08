#include<stdio.h>
#include<stdlib.h>
int main()
{
	//system("要调用的dos指令")即可调用电脑的文件； 
	int i;
	printf("Please inpur i:");
	scanf("%d",&i);
	if(i>1)
	{
		system("mspaint");	
	}
	else
	{
		system("services.msc");
	} 
	return 0;
}