#include<stdio.h>
#include<stdlib.h>
//BF算法是由Brute与Force设计的 
int StrIndex_BF(char *s,char *t)
{
	int i=1,j=1;
	while(i<=s[0]&&j<=t[0])//数组的首位置存储字符串的长度。 
	{
		if(s[i]==t[i])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2;//遇到不相等的字符，回溯。 
			j=1;
		}
	} //end while
	if(j>t[0])
	{
		return (i-t[0]);//匹配成功，返回存储位置。 不需要加一，因为第一个存储空间没有存放字符。 
	}
	else
	{
		return -1;//匹配失败。 
	}
}
int main()
{
	return 0;	
}