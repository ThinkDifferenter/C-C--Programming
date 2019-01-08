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
	printf("%d\n",100);//%d接收的是数值 
	printf("%d\n",i);
	printf("%s\n","jiangjun");//这里的%s实际接收的字符'j'的地址 
	printf("%s\n",str); //%s接收的是地址 
	printf("%d\n",sizeof("jiangjun")); //字符串jiangjnu在C里面会开辟内存！ 
	printf("%d\n",a[6]);
	printf("%d\n",6[a]);
	printf("%d\n",*(a+6));
	printf("%d\n",*(6+a));
	return 0; 
}