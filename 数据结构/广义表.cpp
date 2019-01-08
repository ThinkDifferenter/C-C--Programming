#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct GenealNode
{
	int tag;
	union 
	{
		int date;
		struct
		{
			struct GenealNode *hp,*tp;
		}ptr;
	}	
}*GList;

//取广义表头 
GList GetHead(GList p)
{
	if(!p||p->tag=0)
	{
		printf("空表或是单个原子表!\n");
		return NULL; 
	}
	return (p->ptr.hp);
} 
//取广义表尾 
GList  GetTail(GList p)
{
	if(!p||p->tag=0)
	{
		printf("空表或是单个原子表!\n");
		return NULL; 
	}
	return (p->ptr.tp);	
} 
//求广义表的深度（广义表中所含括号的重数） 
int Depth(GList ls)
{
	int max,dep;
	GList tmp=ls;
	if(tmp==NULL)
	{
		return 1;
	}
	if(tmp->tag==0)
	{
		return 0;	
	}
	max=0;
	while(tmp!=NULL)
	{
		dep=Depth(tmp->ptr.hp);
		if(dep>max)
		{
			max=dep;
		}
		tmp=tmp->ptr.tp;
	}
	return (max+1); 
}  
//建立广义表
char Emp_GList[5]="()";//
int Creat_GList(char *s,GList *L)
{
	GList p,q;
	char sub[256];
	char hsub[256];
	if(strcmp(s,Emp_GList))
	{
		*L=NULL;
		return 1;
	} 
	if(!(*L=(GLIst)malloc(sizeof(GenealNode))))
	{
		return 0;
	} 
	if(strlen(s)==1)
	{
		(*L)->tag=0;
		(*L)->date=*s;
	}
	else
	{
		(*L)->tag=1;
		p=*L;
		StrSub
	}
} 