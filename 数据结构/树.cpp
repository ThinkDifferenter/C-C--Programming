#include<stdio.h>
#include<stdib.h>
#define MaxTreeNodeNum 100 
//树的顺序存储结点 
typedef struct 
{
	int date[MaxTreeNodeNum];//根存储在下标为1的数组单元中 
	int n;//当前完全二叉树的结点个数 
}QBtree;
//树的链式存储结点 
typedef struct bnode
{
	char date;
	struct bnode *lchild,*rchild,*parent;	
}Bnode,*BTree;
int main()
{
	return 0;
}