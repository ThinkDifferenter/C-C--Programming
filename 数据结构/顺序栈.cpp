#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct Stack
//顺序栈是静态分配存储的
//栈中的元素超过给栈分配的最大空间的大小时产生栈的溢出---上溢
//栈中的元素再也没有元素出栈时产生栈的溢出--下溢 
{
	int date[MAXSIZE];//按理论来说，栈没有上限！ 
	int top;//MAXSIZE只是人为的规定，区别于顺序表！ 
}SeqStack,*PSeqstack;
//定义一个指向顺序栈的指针
PSeqstack s=(PSeqstack)malloc(sizeof(SeqStack)); 
//栈的初始化
PSeqstack Init_SeqStack(void)
{
	PSeqstack s;
	s=(PSeqstack)malloc(sizeof(SeqStack));
	if(s)
	{
		s->top=-1;
	}
	return s;
} 
//判空栈
int Empty_SeqStack(PSeqstack s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
//入栈
//x代表插入的新元素 
int Push_SeqStack(PSeqstack s,int x)
{
	if(s->top==MAXSIZE-1)
	{
		return 0;	
	}
	else
	{
		s->top++;
		s->date[s->top]=x;
		return 1;
	}
} 
//出栈 即删除栈顶的元素 
//删除栈顶的元素保留在*x 
int Pop_SeqStack(PSeqstack s,int *x)
{
	if(Empty_SeqStack(s))
	{
		return 0;
	}	
	else
	{
		*x=s->date[s->top];
		s->top--;
		return 1; 
	}
} 
//取栈顶元素
//取出的元素放在*x，栈不发生改变 
int Get_SeqStack(PSeqstack s,int *x)
{
	if(Empty_SeqStack(s))
	{
		return 0;
	}	
	else
	{
		*x=s->date[s->top];
		return 1;
	}
} 
//销毁栈->释放内存
// 要修改栈的指针变量 ，所以传入栈的指针 
void Destroy_SeqStack(PSeqstack *s)//传入的是指针的地址！！！ 
{
	if(*s)
	{
		free(*s);
	}
	*s=NULL;
} 
int main()
{
	return 0;	
}