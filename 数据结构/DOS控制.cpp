#include<stdio.h>
#include<stdlib.h>
int main()
{
	//system("Ҫ���õ�dosָ��")���ɵ��õ��Ե��ļ��� 
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