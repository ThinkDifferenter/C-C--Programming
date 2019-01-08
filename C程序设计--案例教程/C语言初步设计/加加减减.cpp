#include<stdio.h>
main()
{
 int i=2;
 int j=3;
 int p;
 
	// printf("%d %d\n",i++,i);//覆盖i的值！ 逐步注释 
	// printf("%d %d\n",++i,i); //或者逐步初始化！ 
	// printf("%d %d\n",p=-i++,i);
	// printf("%d %d %d\n",p=i+++j,i,j); 
	// printf("%d %d %d\n",p=i+--j,i,j);
	// printf("%d %d %d\n",p=i+++--j,i,j); 
	// printf("%d %d\n",p=i+++i++,i);
	 printf("%d %d\n",p=++i+(++i),i);

 return 0;
 
 
}


