#include <stdio.h> 
#include <stdlib.h> 
int add(int a, int b); 
int sub(int a, int b); 
int main(void) 
{ 
  
 int (*p[2])(int ,int);   // ��ʵ�ʺ�ָ������ָ����һ���� 
 p[0] = add; 
 p[1] = sub;  
 printf("%d\n", p[0](5,3)); 
 printf("%d\n", p[1](5,3));  
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