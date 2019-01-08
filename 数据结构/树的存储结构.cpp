#include<stdio.h>
#include<stdlib.h>
#define MaxNodeNum 100 
//双亲表示法： 
//树的双亲表示法主要描述的是结点的双亲关系，采用顺序存储结构
//这种存储的方法特点是寻找结点的双亲很容易，但寻找结点的孩子比较困难 
typedef struct
{
	int date;
	int parent;//parent表示结点所在的层次，根节点的parent为-1 
}ParentList;
typedef struct 
{
	ParentList elem[MaxNodeNum];
	int n;//表示当前的结点数目 
}ParentTree;


//孩子表示法： 
//树的孩子表示法主要描述的是结点的孩子关系，由于每个结点的孩子个数不确定，所使用链式存储的方式 
//将所有结点的表头存放在一位数组中。


//孩子兄弟表示法
//树的孩子兄弟表示法是一种链式结构，它通过描述每一个结点的一个孩子和兄弟信息来反映结点之间的层次关系
typedef struct node 
{
	int date;
	struct node *firstson,*nextbrother;
	//firstson为指向该结点第一个孩子的指针，nextbrother为指向下一个兄弟的指针	
}Tnode;
 