#include<stdio.h>
main()
{int price=0;
 int bill=0;
 
 printf("���������Ľ�\n");
 scanf("%d",&price);
 
 printf("����������Ʊ�棻\n");
 scanf("%d",&bill);
 
 if(bill>=price)
 { printf("Ӧ��������%d",bill-price);}
 else
 { printf("���Ľ���������������Ʊ�棬лл��\n");} 
 
 return 0;
}
