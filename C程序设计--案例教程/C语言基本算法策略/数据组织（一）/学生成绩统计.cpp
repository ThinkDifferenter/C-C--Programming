#include<stdio.h>
#define N1 6
#define N2 4 
int main()
{
	int no[N1],nok[N1][N2];
	int i,j,k,k1,num,num1,num2,num3,num4,num5,numk;
	double p[N1][N2],max1,sum=0.0;
	
	for(j=0;j<N2;j++)
	{
		if(j==0)  printf("Please input chinese grades:\n");
		else if(j==1)  printf("Please input math grades:\n");
		else if(j==2)  printf("Please input english grades:\n");
		else printf("Please input computer grades:\n");
		
		for(i=0;i<N2;i++)
		{
			printf("No.%d?",i+1);
			scanf("%lf",&p[i][j]);
		}
	}	
	for(j=0;j<N2;j++)
	{
			max1=p[0][j];
			for(i=0;i<N1;i++)
			{
				if(max1<p[i][j])
				{
					max1=p[i][j];
					sum+=p[i][j];
				}
			}
			num=1;
			numk=1;
			for(i=0;i<N1;i++)
			{
				if(max1==p[i][j])
				{
					no[num]=i+1;
					num++;
				}
				
				if(p[i][j]<60.0)
				{
					nok[num][j]=i;
					numk++;
				}
			}
			if(j==0)
			{
				num1=numk-1;
				printf("chinese highest grades is %lf\n",max1);
				printf("No:\n");
			}
			
			else if(j==1)
			{
				num2=numk-1;
				printf("math highest grades is %lf\n",max1);
				printf("No:\n");
			}
			else if(j==2)
			{
				num3=numk-1;
				printf("chinese highest grades is %lf\n",max1);
				printf("No:\n");
			}
			else 
			{
				num4=numk-1;
				printf("chinese highest grades is %lf\n",max1);
				printf("No:\n");
			}
			for(i=1;i<=num-1;i++)
			{
				printf("No.%d\n",no[i]);
			}
			
			printf("\n单科成绩不及格者:\n");
			printf("==========================================\n");
			if(num1==0)
			{
				printf("语文无不及格者!\n");
			}
			else
			{
				printf("\n\n语文不及格者\n");
				printf("\n学号  语文  数学  英语  计算机\n");
			}
			for(k=1;k<=num1;k++)
			{
				k1=nok[k][0];
				printf("No.%d:",k1+1);
				printf("%-10.4lf%-10.4lf%-10.4lf%-10.4lf",p[k1][0],p[k1][1],
				p[k1][2],p[k1][3]);
			}
			if(num2==0)
			{
				printf("数学无不及格者\n"); 
			}
			else
			{
				printf("\n\n数学不及格者\n");
				printf("\n学号  语文  数学  英语  计算机\n");
			}
			for(k=1;k<=num2;k++)
			{
				k1=nok[k][1];
				printf("No.%d:",k1+1);
				printf("%-10.4lf%-10.4lf%-10.4lf%-10.4lf",p[k1][0],p[k1][1],
				p[k1][2],p[k1][3]);
			}
			if(num3==0)
			{
				printf("英语无不及格者\n"); 
			}
			else
			{
				printf("\n\n英语不及格者\n");
				printf("\n学号  语文  数学  英语  计算机\n");
			}
			for(k=1;k<=num3;k++)
			{
				k1=nok[k][2];
				printf("No.%d:",k1+1);
				printf("%-10.4lf%-10.4lf%-10.4lf%-10.4lf",p[k1][0],p[k1][1],
				p[k1][2],p[k1][3]);
			}
			if(num4==0)
			{
				printf("计算机无不及格者\n"); 
			}
			else
			{
				printf("\n\n计算机不及格者\n");
				printf("\n学号  语文  数学  英语  计算机\n");
			}
			for(k=1;k<=num4;k++)
			{
				k1=nok[k][3];
				printf("No.%d:",k1+1);
				printf("%-10.4lf%-10.4lf%-10.4lf%-10.4lf",p[k1][0],p[k1][1],
				p[k1][2],p[k1][3]);
			}
		
	}
	printf("=================================\n");
	printf("全部学生全部课程的总平均分=%10.6lf",sum/N1/N2);
	return 0; 
}
