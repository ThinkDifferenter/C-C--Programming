#include<stdio.h>
void search(double (*p)[4],int n);//注意函数原型的声明 
int main()
{
	double a[3][4]={{65,67,70,60},{80,87,90,81},{90,99,100,98}};
	search(a,3);//间接引用2，定义一个指向一行的行指针，初始化 int (*p)[m]=a; 
	return 0;
} 
void search(double (*p)[4],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<4;j++)
		{
			if(*(*(p+i)+j)<60)
			{
				printf("NO.%d fails,his score are:\n",i+1);
				for(j=0;j<4;j++)
				{
					printf("%.2f\t",*(*(p+i)+j));
				}
				printf("\n");
			}
		}
	}
}