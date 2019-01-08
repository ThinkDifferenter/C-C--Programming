#include<stdio.h>
#include<stdlib.h>
//求数组个元素之和函数
int sum(int a[],int l,int h)//l for low,h for high 
{
	int result;
	if(l==h)
	{
		result=a[l];	
	}
	else
	{
		result=(sum(a,l,h-1)+a[h]);
	}
	return result;
} 
//递归算法解决全排问题
void Swape(int a[],int i,int j)
{
	 int t;
	 t=a[i];
	 a[i]=a[j];
	 a[j]=t;	
} 
void Perm(int list[],int k,int m)
{
	int i;
	if(k==m)
	{
		for(i=0;i<=m;i++)
		{
			printf("%d",list[i]);
		} 
		printf("\n");
	}
	else
	{
		for(i=k;i<=m;i++)
		{
			Swape(list,k,i);
			Perm(list,k+1,m);
			Swape(list,k,i); 
		}
	}
}

//递归算法倒置字符串
void ConverseStr(char *str,int start,int end)
{
	char t;
	if(end-start<1)
	{
		return ;
	}
	else
	{
		t=str[start];
		str[start]=str[end];
		str[end]=t;//交换对应位上的字符!!! 
		ConverseStr(str,start+1,end-1);
	}
} 

//火车进站问题递归算法
//设某一时刻站台入口有i列火车，站台内有j列火车
//（1）站台入欧处第一列火车入站台
//（2）站台内最顶上的火车出站 
//理解每一次操作！！！ 
int Train_into_PlantForm(int i,int j)
{
	if(i==0)//站外没有火车 
	{
		return 1;
	} 
	else if(j==0)//站内没有火车  
	{
		return Train_into_PlantForm(i-1,1);
	}
	else
	{
		return Train_into_PlantForm(i-1,j+1)+Train_into_PlantForm(i,j-1);
	} 
	
} 
 
int main()
{
	return 0;
} 