#include<stdio.h>
int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int (*p)[4],i,j;
	p=a;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",*(*(p+i)+j));
		}
		printf("\n");
	}
	printf("���������������:");
	scanf("%d",&i);
	printf("%d�е�Ԫ�طֱ�Ϊ:",i);
	for(j=0;j<4;j++)
	{
		printf("%d\t",*(*(p+i-1)+j));
	} 
	printf("\n");
	return 0;
}