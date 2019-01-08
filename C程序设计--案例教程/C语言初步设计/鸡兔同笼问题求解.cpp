#include<stdio.h>
main()
{
	//鸡兔同笼问题求解! 
	int x,y,z;
	
	for(x=1;x<=19;x++)
	for(y=1;y<=33;y++)
	for(z=1;z<=100;z++)
	
	if(z%3==0&&x+y+z==100&&5*x+3*y+z/3==100)
	
	printf("x=%d,y=%d,z=%d\n",x,y,z);
			
	
	return 0;
	 
}
