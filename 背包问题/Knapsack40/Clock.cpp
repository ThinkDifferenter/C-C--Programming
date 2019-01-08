#include<stdio.h>

int main()
{
	int hour;
	int minute;
	int second;
	
	for(hour=0;hour<=23;hour++)
	{
		for(minute=0;minute<=59;minute++)
		{
			for(second=0;second<=59;second++)
			{
				printf("%d : %d : %d\n",hour,minute,second);
			}
		}	
	}
	
	printf("24 :  0 :  0\n");
	return 0;		
}