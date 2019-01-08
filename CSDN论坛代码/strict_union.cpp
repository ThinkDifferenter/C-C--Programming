#include<stdio.h>
int main()
{
	struct
	{
	        int a;
	        union
	        {
	                struct 
	                {
	                        int x;
	                        int y;
	                 }log;
	        };
	}send;
	send.log.x=13;
	
	printf("%d\n",send.log.x);
return 0;
}
