#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 256
typedef struct node
{
	int i,j;//非零元素所在的行和列 
	int v;	//非零元素的值 
}triple;
typedef struct Node
{
	triple date[MAXSIZE];//三元组表的最大元素的个数（三原组表实际上是行列式） 
	int  m,n,t;//行数，列数，个数 
}tripletable;

//三元组表转置
//跳着找，顺着存 ：对A中的每一列col（1<=col<=n）,通过从头到尾扫描三元表a.date，找出所有列号
//等于col的那些三元组，将它们的行号和列号互换后依次放入b.date中，即可得到B的按行优先的压缩存储表示 
tripletable transmatrix(tripletable a)
{
	tripletable b;
	int p,q,col;
	b.m=a.n;
	b.n=a.m;
	b.t=a.t;
	if(b.t)
	{
		q=0;
		for(col=1;col<=a.n;col++)
		{
			for(p=0;p<a.t;p++)
			{
				if(a.date[p].j==col)
				{
					b.date[q].i=col;
					b.date[q].j=a.date[p].i;
					b.date[q].v=a.date[p].v;
					q++;
				}//end if
			}//end in for
		}//end out for
	}//end if
	return b;
}
//顺着找，跳着存
//对A扫描一次，按A第二列提供的列号一次确定位置装入B的三元组表中，
//一遍扫描先确定三元组的位置关系，二次扫描由位置关系装入三元组。 
//num[j]表示Aj矩阵第j列下一个非零元素个数，pot[j]表示矩阵A中第J列下一个非零元素在B中应存放的位置 
tripletable fasttranstri(tripletable a)
{
	tripletable b;
	int p,q,col,k;
	int num[a.n+1];
	int pot[a.n+1];
	b.m=a.n;
	b.n=a.m;
	b.t=a.t;
	if(b.t)
	{
		for(col=1;col<=a.n;++col)
		{
			num[col]=0;
		}
		for(k=0;k<a.t;++k)
		{
			++num[a.date[k].j];
		}
		pot[1]=0;
		for(col=2;col<=a.n;++col)
		{
			pot[col]=pot[col-1]+num[col-1];
		} 
		for(p=0;p<a.t;++p)
		{
			col=a.date[p].j;
			q=pot[col];
 
			++pot[col];
		}
	}
	return b;
} 