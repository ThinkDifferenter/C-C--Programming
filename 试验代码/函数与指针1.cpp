#include <stdio.h> 
#include <stdlib.h> 
int add(int a, int b); 
int sub(int a, int b); 
int  main(void) 
{ 
  
 int (*p)(int a, int b);   // ��ʵ�ʺ�ָ������ָ����һ���� 
 p = add; 
 printf("%d\n", p(5,3));
 p = sub;   
 printf("%d\n", p(5,3)); 
 return 0; 
} 
 
int add(int a, int b) 
{ 
 return  a + b; 
} 
 
int sub(int a, int b) 
{ 
 return  a - b; 
} 