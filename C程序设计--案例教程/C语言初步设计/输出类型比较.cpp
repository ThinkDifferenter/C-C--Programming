#include<stdio.h>
main()
{
 int a=164;
 int b=-1;
 char ch='A';
 float c=-12.3;
 
  
	 
	 printf("%d\n",a);//%d or %i 十进制输出 整型 
	 printf("%x\n",a);//%x or %X  十六进制输出
	 printf("%X\n",a);
	 printf("%o\n",a);//八进制输出
	 printf("%u\n",b);//十进制输出 无符号型 
	 printf("%c\n",ch);//输出一个字符 
	 printf("My name is %s\n","JiangJun");//输出一个字符串 important!
	 printf("%f\n",c);//浮点型输出 
	 printf("%e\n",c);//%e or %E浮点型指数输出 
	 printf("%E\n",c);
	 printf("%p\n",&a);//指针输出  
 
 return 0;
 
} 


