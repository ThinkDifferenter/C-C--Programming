#include <stdio.h>
int main()
{
    int a[5] = {1,2,4,3,1};//原始数组，不是回文数组。
    int i;
    int *head, *end;//定义两个指针。
    head = a;//head指向头。
    end = &a[4]; //end指向尾。
    
    while(head > end)//循环条件设置为head>end,即当end<=head时退出循环。
    {
        if(*head != *end)
			 *end = *head; //如果不等，则使其相等。
    }
    for(i=0;i<5;i++)//输出结果
     {
     	 printf("%d ", a[i]);	
     }  
    return 0;
}