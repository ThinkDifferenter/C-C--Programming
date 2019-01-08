#include<stdio.h>
int main()
{
	char str[100];
	int i,num=0,flag=0;
	printf("ÇëÊäÈëÒ»´®×Ö·û:\n");
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			flag=0;
		}
		else if(flag==0)
		{
			flag=1;
			num++;
		}
	}
	printf("Õâ´®×Ö·ûÓĞ%d¸ö×Ö·û´®.\n",num);
	return 0;
}