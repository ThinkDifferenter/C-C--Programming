#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h> 
#include <time.h> 

#define pi 3.14159

double GaussGenerate(double mu, double theda)
//muΪ��ֵ��thedaΪ����
{
  double t1,t2,a,r;
  double x;
  /*�����������ȷֲ���0~1���������*/ 
  t1 = rand()/(RAND_MAX);
  t2 = rand()/(RAND_MAX);
  /*�������������������ֲ�����*/
  a = 2*pi*t1;            //a�Ǽ�����ĽǶȣ������0~2*pi�ľ��ȷֲ�
  r = sqrt(-2*log(t2));   //r�Ǽ�����ľ��룺�����Ȼ���������ŵ�һ�ֲַ�
  /*�ü�����(a,r)ת���ɵѿ�������(x,y)������ǲ����ĸ�˹������*/
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