#include<stdio.h>
int greatcommDivis(int a,int b);
int lastCommMult(int a,int b);
int main()
{
	int a,b,c;
	
	printf("Please enter the integer a,b:");
	scanf("%d %d",&a,&b);
	printf("choose:\n");
	printf("1 greatest common disvisor!\n");
	printf("2 least common multiple!\n");
	scanf("%d",&c);
	
	if(c==1)
	{
		printf("the greatest common divisor of a,b is %d\n",greatcommDivis(a,b));
	}
	if(c==2)
	{
		printf("the least common multiple of a,b is %d\n",lastCommMult(a,b));
	}
	return 0;
}
//最大公约数 
int greatcommDivis(int a,int b)
{
	int r,tmp;
	if(a<b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	do
	{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
//最小公倍数 
int lastCommMult(int a,int b)
{
	int i,tmp;
	if(a<b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	for(i=1;;i++)
	{
		tmp=i*a;
		if(tmp%b==0)
		{
			return tmp;
		}
	}
}