#include<stdio.h>
main()
{
 int i=2;
 int j=3;
 int p;
 
	// printf("%d %d\n",i++,i);//����i��ֵ�� ��ע�� 
	// printf("%d %d\n",++i,i); //�����𲽳�ʼ���� 
	// printf("%d %d\n",p=-i++,i);
	// printf("%d %d %d\n",p=i+++j,i,j); 
	// printf("%d %d %d\n",p=i+--j,i,j);
	// printf("%d %d %d\n",p=i+++--j,i,j); 
	// printf("%d %d\n",p=i+++i++,i);
	 printf("%d %d\n",p=++i+(++i),i);

 return 0;
 
 
}


