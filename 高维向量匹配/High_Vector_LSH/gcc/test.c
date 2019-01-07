#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h> 
#include <time.h> 

#define pi 3.14159

double GaussGenerate(double mu, double theda)
//mu为均值，theda为方差
{
  double t1,t2,a,r;
  double x;
  /*产生两个均匀分布的0~1的随机序列*/ 
  t1 = rand()/(RAND_MAX);
  t2 = rand()/(RAND_MAX);
  /*极坐标的两个随机变量分布序列*/
  a = 2*pi*t1;            //a是极坐标的角度：变成了0~2*pi的均匀分布
  r = sqrt(-2*log(t2));   //r是极坐标的距离：变成自然对数开根号的一种分布
  /*用极坐标(a,r)转换成笛卡尔坐标(x,y)，这就是产生的高斯白噪声*/
  x = r*cos(a);

  return mu+theda*x;
}


void Gauss(double gs[], int lengh, double mu, double theda)
{
	int i=0;
    for( i=0;i<lengh;i++)
    {
    	gs[i]=GaussGenerate(mu,theda);	
    }   
}

int main()
{
	int i=0;
	double array[1024];
	Gauss(array,1024,0.0,1.0);
	
	for(i=0;i<1024;i++)
	{
		printf("%f\t",array[i]);
	}
	return 0;
}