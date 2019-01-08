#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	struct node *next;
} StackNode,*PStackNode;
//链式栈的头部做栈顶 
//方便操作和强调栈顶是栈的一个属性  
//定义一个包含指向栈结点的结构指针的结构 
typedef struct Node 
{
	PStackNode top;	
}LinkStack,*PLinkStack;
//定义指向链式栈的指针 
PLinkStack s=(PLinkStack)malloc(sizeof(LinkStack));
//初始化空栈 
PLinkStack Init_LinkStack(void)
{
	PLinkStack s;
	s=(PLinkStack)malloc(sizeof(LinkStack));
	if(s)
	{
		s->top=NULL;
	}
}
//判断栈 
int Empty_LinkStack(PLinkStack s)
{
	return (s->top==NULL);	
} 
//入栈 
int Push_LinkStack(PLinkStack s,int x)
{
	PStackNode p;
	p=(PStackNode)malloc(sizeof(StackNode))//Attation!!!
	if(!p)
	{
		printf("??????!\n");
		return 0; 
	} 
	p->date=x;
	p->next=s->top;
	s->top=p;
	return 1;
} //出栈 
int  Pop_LinkStack(PLinkStack s,int *x)//*x保存删除的数据 
{
	PStackNode p;
	if(Empty_LinkStack(s))
	{
		printf("Empty Stack!cannot operator!\n")
		return 0;
	}	
	*x=s->top->date;
	p=s->top;//p指向栈顶结点 
	s->top=s->top->next;//栈指针指向删除前栈顶的下一个结点 
	free(p);//释放栈顶结点 
	return 1;
} 
//取栈顶元素 
// *x保存取出来的元素 
int GetTop_LinkStack(PLinkStack s,int *x)
{
	if(Empty_LinkStack(s))
	{
		printf("Empty Stack!\n");
		return 0;
	}
	*x=s->top->date;
	return 1; 
} 
//销毁栈 
void Destroy_LinkStack(PLinkStack *ls) //函数形参是指向栈指针的指针 
{
	PStackNode p,q;
	if(*ls)
	{
		p=(*ls)->top;
		while(p)
		{
			q=p;
			p=p->next;
			free(q);
		}
		free(*ls);
	}
	*ls=NULL;
}