#include<stdio.h>
main()
{
 int i,a,num=0;
 float sum=0;
	//多个数求和！ 
	 for(i=0;i<=10;i++)
	 {
	 // printf("Please input some number:"); ???????
	  scanf("%d",&a);
	  if(a<=0) continue;
	  num++;
	  sum=sum+a;
	  
	 }
	 printf("%d plus integer's sum:%.0f\n",num, sum);
	 printf("average value:%.2f\n",sum/num);
	 
 return 0;
 
} 


