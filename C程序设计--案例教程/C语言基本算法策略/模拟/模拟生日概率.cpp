#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//ģ����֤50�˵İ༶���������˵�������ͬ�ĸ���Ϊ97% 
int main()
{
	int a=0,bir[51],i,j,k,t;
	
	for(k=1;k<=100;k++)//�ٷֱ�1~100% 
	{
		t=0;
		srand(time(00));
		for(i=1;i<=50;i++)//50λͬѧ 
		{
			bir[i]=rand()%365+1;//�������50������ 
		}
		for(i=1;i<=49;i++)
		{
			for(j=i+1;j<=50;j++)
			{
				if(bir[i]==bir[j])
				{
					t=1;
					a++;
					break;
				}
			}
			if(t==1)
			{
				break;
			}
		}
	}	
	printf("50�˵İ༶����ͬ����ͬѧ�ĸ���Ϊ:%d%%\n",a);
	return 0;
}