#include<stdio.h>
#include<stdlib.h>
//KMP模式匹配算法是克努斯（Knuth），莫里斯（MOrris）和普拉特（Prattle）同时设计的 
//相比BF模式匹配算法，KMP模式匹配算法更好的利用了模式与主串的比较信息，没有直接回溯，
//而是通过next 函数判断模式t应该回到主串出现不与模式t相等的 
int StrIndex_KMP(char *s,char *t,int pos)
//从串s的第pos个字符开始找首次与串t（模式）相等的子串 
{
	int i=pos,j=1;
	while(i<=s[0]&&j<=t[0])
	{
		if(j==0||s[i]==t[j])
		{
			i++;
			j++; 
		}
		else
		{
			j=next[j];
		}
	}//end while
	if(j>t[0])
	{
		return (i-t[0]);
	}
	else
	{
		return -1;
	}
}
//next函数求得模式t要在主串上滑动的距离。 
void GetNext(char *t,int next[])
//求模式t的next值并存入next数组中，字符串长度保存在t[0]中。 
{
	int i=1,j=0;
	next[1]=0;
	while(i<t[0])
	{
		if(j==0||t[i]==t[j])
		{
			++i;
			++j;
			next[i]=j;
		}	
		else
		{
			j=next[j];
		}
	}//end while
}
//递归算法求next值
void GetNext_Recursion(char *t,int next[],int L)
//求模式和t的next值并存入next数组中，参数t为模式串，L为模式串的长度（t[0]），
//算法结束时，字符串t的next数组值保存在next[]中，从下标1开始存储！ 
{
	if(L==1)
	{
		next[1]=0;
		return ;
	}	
	GetNext_Recursion(t,next,L-1);
	int k=next[L-1];
	while(1)
	{
		if(t[k]==t[L-1])
		{
			next[L]=k+1;
			return ;
		}
		k=next[k];
		if(k==0)
		{
			next[L]=1;
			return ;
		}
	}
} 
int main()
{
	return 0; 
} 