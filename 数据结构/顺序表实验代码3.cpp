#include<stdio.h>
int main()
{
	char str[10]="jiangjun";
	printf("%c\n",str[0]);
	printf("%s\n",str);
	for(int i=3;i<10;i++)
	{
		str[i-1]=str[i];
	}
	printf("%s\n",str);
	for(int i=10-1;i>=3-1;i--)//���i��λ�ϲ�������ʱ��i��λ�ϵ�����Ҫ�����ƶ��� 
	{
		str[i+1]=str[i];
	}
	str[3-1]='a';
	printf("%s\n",str);
	return 0;
}