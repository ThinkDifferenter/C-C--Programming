#include<stdio.h>
main()
{
	//����ͬ���������! 
	int x,y,z;
	
	
	for(x=1;x<=19;x++)
	for(y=1;y<=33;y++)
	
	{
		y=100-x-z;
		if(y>0&&5*x+3*y+z/3==100)
		{
			printf("x=%d,y=%d,z=%d\n",x,y,z);
		}
	}
	return 0;
}
