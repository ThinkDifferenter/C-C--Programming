#include<stdio.h>
int main()
{
	int a[10];
	a[6]=10;
	6[a]=10;
	int i=100;
	char *str="jiangjun";
	printf("the size of array is %d\n",sizeof(a));
	printf("%p\n",a);
	printf("%p\n",&a[0]);
	printf("%d\n",100);//%d���յ�����ֵ 
	printf("%d\n",i);
	printf("%s\n","jiangjun");//�����%sʵ�ʽ��յ��ַ�'j'�ĵ�ַ 
	printf("%s\n",str); //%s���յ��ǵ�ַ 
	printf("%d\n",sizeof("jiangjun")); //�ַ���jiangjnu��C����Ὺ���ڴ棡 
	printf("%d\n",a[6]);
	printf("%d\n",6[a]);
	printf("%d\n",*(a+6));
	printf("%d\n",*(6+a));
	return 0; 
}