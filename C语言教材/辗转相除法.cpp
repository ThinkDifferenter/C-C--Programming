#include<stdio.h>
main()
{
	int m,n,r=1;
	int i,j;
	printf("Please input m,n:");
	scanf("%d %d",&m,&n);
	i=m,j=n;
	//շת�������⣡�� 
	r=m%n;
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	printf("���Լ��:%d\n",n);
	printf("��С������:%d\n",(i*j)/n);
	return 0;
}
