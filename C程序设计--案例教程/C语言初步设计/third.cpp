/*This is the third C program*/
#include<stdio.h>
main()
{
	int x,y,z;
	scanf("%d %d",&x,&y);
	z=max(x,y);
	printf("max=%d\n",z);
	
}

int max(int a,int b)
{ 
int c;
if(a>b)
c=a;
else
c=b;
return (c);

}
