#include<stdio.h>
#include<stdib.h>
#define MaxTreeNodeNum 100 
//����˳��洢��� 
typedef struct 
{
	int date[MaxTreeNodeNum];//���洢���±�Ϊ1�����鵥Ԫ�� 
	int n;//��ǰ��ȫ�������Ľ����� 
}QBtree;
//������ʽ�洢��� 
typedef struct bnode
{
	char date;
	struct bnode *lchild,*rchild,*parent;	
}Bnode,*BTree;
int main()
{
	return 0;
}