#include<stdio.h>
#include<stdlib.h>
#define MaxNodeNum 100 
//˫�ױ�ʾ���� 
//����˫�ױ�ʾ����Ҫ�������ǽ���˫�׹�ϵ������˳��洢�ṹ
//���ִ洢�ķ����ص���Ѱ�ҽ���˫�׺����ף���Ѱ�ҽ��ĺ��ӱȽ����� 
typedef struct
{
	int date;
	int parent;//parent��ʾ������ڵĲ�Σ����ڵ��parentΪ-1 
}ParentList;
typedef struct 
{
	ParentList elem[MaxNodeNum];
	int n;//��ʾ��ǰ�Ľ����Ŀ 
}ParentTree;


//���ӱ�ʾ���� 
//���ĺ��ӱ�ʾ����Ҫ�������ǽ��ĺ��ӹ�ϵ������ÿ�����ĺ��Ӹ�����ȷ������ʹ����ʽ�洢�ķ�ʽ 
//�����н��ı�ͷ�����һλ�����С�


//�����ֵܱ�ʾ��
//���ĺ����ֵܱ�ʾ����һ����ʽ�ṹ����ͨ������ÿһ������һ�����Ӻ��ֵ���Ϣ����ӳ���֮��Ĳ�ι�ϵ
typedef struct node 
{
	int date;
	struct node *firstson,*nextbrother;
	//firstsonΪָ��ý���һ�����ӵ�ָ�룬nextbrotherΪָ����һ���ֵܵ�ָ��	
}Tnode;
 