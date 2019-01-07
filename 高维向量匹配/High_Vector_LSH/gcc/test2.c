#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h> 
#include <time.h> 

#define NSUM 25
#define PI 3.141592654double 

float gaussrand1()
{
     float x = 0;
     int i;
     for(i = 0; i < NSUM; i++)
     {
         x += (float)rand() / RAND_MAX;
     }

     x -= NSUM / 2.0;
     x /= sqrt(NSUM / 12.0);

     return x;
}


float b_Random(int min,int max)
{
	float R = 0.0;
	//srand(time(NULL));
	R = rand() % (max - min) + min;

	return R;
}

int main()
{
	int i=0;
	float array[1024];
	
	for(i=0;i<1024;i++)
	{
		array[i]=gaussrand1();
		printf("%f\t",array[i]);
	}
	
	float f;
	
	f=b_Random(0,1000);
	printf("\n\n%f\t",f);

	
	return 0;
}