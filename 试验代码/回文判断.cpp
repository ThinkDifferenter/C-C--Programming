#include <stdio.h>
int main()
{
    int a[5] = {1,2,4,3,1};//ԭʼ���飬���ǻ������顣
    int i;
    int *head, *end;//��������ָ�롣
    head = a;//headָ��ͷ��
    end = &a[4]; //endָ��β��
    
    while(head > end)//ѭ����������Ϊhead>end,����end<=headʱ�˳�ѭ����
    {
        if(*head != *end)
			 *end = *head; //������ȣ���ʹ����ȡ�
    }
    for(i=0;i<5;i++)//������
     {
     	 printf("%d ", a[i]);	
     }  
    return 0;
}