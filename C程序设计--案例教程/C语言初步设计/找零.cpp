#include<stdio.h>
main()
{int price=0;
 int bill=0;
 
 printf("请输入您的金额；\n");
 scanf("%d",&price);
 
 printf("请输入您的票面；\n");
 scanf("%d",&bill);
 
 if(bill>=price)
 { printf("应该找您；%d",bill-price);}
 else
 { printf("您的金额不够！请增大您的票面，谢谢！\n");} 
 
 return 0;
}
