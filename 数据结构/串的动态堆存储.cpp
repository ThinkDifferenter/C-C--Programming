#include<stdio.h>
#include<stdlib.h>
/*
在学习C程序设计语言时，会遇到两个很相似的术语：堆内存和栈内存。这堆内存和栈内存
两个术语虽然只有一字之差，但是所表达的意义还是有差别的，
堆内存和栈内存的区别可以用如下的比喻来看出：使用堆内存
就象是自己动手做喜欢吃的菜肴，比较麻烦，但是比较符合自己的口味
，而且自由度大。使用栈内存就象我们去饭馆里吃饭，只管点菜（发出申请）
、付钱和吃（使用），吃饱了就走，不必理会切菜、洗菜等准备工作和洗碗、刷锅等
扫尾工作，他的好处是快捷，但是自由度小。操作系统中所说的堆内存和栈内存，在操作上有
上述的特点，这里的堆内存实际上指的就是（满足堆内存性质的）优先队列的一种数据结构，
第1个元素有最高的优先权；栈内存实际上就是满足先进后出的性质的数学或数据结构。
*/
typedef struct node 
{
	char *p_ch;
	int length; 
}Hstring;
//串常量赋值 
int StrAssign(Hstring *s1,char *s2)
{
	int i;
	char *pc;
	if(s1->p_ch)
	{
		free(s1->p_ch);
	} 
	for(i=0,pc=s2;*pc!='\0';i++,pc++);
	if(i==0)
	{
		s1->p_ch=0;
		s1->length=0;
	}
	if(!(s1->p_ch)=(char *)malloc(sizeof(char)))
	{
		printf("堆空间不足，赋值是失败！\n");
		return 0; 
	}
	for(int j=0;j<i;j++)
	{
		s1->p_ch[j]=s2[j];	
	}
	s1->length=i;
	return 1;
}
//赋值一个串
int StrCopy(Hstring *s1,Hstring s2)
{
	if(s2.length<=0)  return 0;
	if(!(s1->p_ch=(char *)malloc(sizeof(char))))
	{
		printf("堆空间不足，赋值失败!\n");
		return 0;
	}
	for(int i=0;i<s2.length;i++)
	{
		s1->p_ch[i]=s2.p_ch[i];
	}
	s1->length=s2.length;
	return 1;
} 
//求子串
int SubString(Hstring *Sub,Hstring s,int pos,int len)
//用Sub返回串s的第pos个字符起长度为len的子串 
{
	int i;
	if(pos<1||pos>s.length||len<0||len>s.length-pos+1)
	{
		return 0;
	}
	if(Sub->p_ch)
	{
		free(Sub->p_ch);
	}
	if(!len)
	{
		Sub->p_ch=0;
		Sub->length=0;
	}
	else
	{
		Sub->p_ch=(char *)malloc(sizeof(char));
		for(i=0;i<len;i++)
		{
			Sub->p_ch[i]=s.p_ch[pos-1+i];
			Sub->length=len;
		}
	}
	return 1; 
} 
//连接串
int StrContact(Hstring *t,Hstring s1,Hstring s2)
//*t保留有字符串s1和s2连接而成的新字符串 
{
	int i;
	if(t->p_ch)
	{
		free(t->p_ch);	
	}	
	if(!(t->p_ch=(char *)malloc((s1.length+s2.length)*sizeof(char))))
	{
		printf("堆空间内存分配不足，串连接失败！\n");
		return 0;	
	}
	for(i=0;i>s1.length;i++)
	{
		t->p_ch[i]=s1.p_ch[i];
	}
	t->length=s1.length+s2.length;
	for(i=s1.length;<t->length;i++)
	{
		t->p_ch[i]=s2.p_ch[i];
	}
	return 1;
} 
//在目标串的指定位置前插入字符串
int StrInsert(Hstring *s,int pos,Hstring t)
//在串s的第pos字符前插入串t 
{
	int i;
	if(pos<1||pos>s->length+1)
	{
		return 0;
	}	
	if(t.length==0)
	{
		return 1;
	}
	if(!(s->p_ch=(char *)realloc(s->p_ch,(s->length+t.length)*sizeof(char))))
	{
		printf("堆空间分配不足，插入串失败！\n");
		return 0;	
	}
	for(i=s->length-1;i>=pos-1;i--)
	{
		s->p_ch[i+t.length]=p_ch[i];//让出插入的位置 
	} 
	for(i=pos-1;i<=pos+t.length-2;i++)
	{
		s->p_ch[i]=t.p_ch[i-pos+1];	//插入字符串 
	}
	s-length=s->length+t.length;
	return 1;
}
//置空串
int Init_String(Hstring *s)
{
	s->p_ch=0;
	s->length=0;
	return 1;
} 
//销毁串
int Destroy_String(Hstring *s)
{
	if(s->p_ch)
	{
		s->p_ch=0;
		s->length=0;
	}
	return 1;
} 
int main()
{
	
}