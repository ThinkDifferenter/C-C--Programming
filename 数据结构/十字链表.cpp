#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int row,col;
	struct node *down,*right;
	union 
	{
		struct node *next;
		int value;
	};
}crosslist;
//��ͷ������ͷ����row��col��ֵ��Ϊ�㣬��ͷ����rightָ����ָ���������ĵ�һ�����,����downָ��Ϊ�� 
//��ͷ����downָ����ָ���������ĵ�һ����㣬����rightָ��Ϊ��
//���е��У�����������Ƕ�Ӧ����ͷ������ͷ��㹹��һ��ѭ������
//ʮ������ͷ����row��col��ִ��ϡ����������������������ͷ����nextָ����ͷ���ĵ�һ��ͷ���
//down��rightָ��ָ��NULL
crosslist *creatclinkmat()
{
	int m,n,t,k,i,j,v,s;
	crosslist *p,*q,*head,*cp[100];
	printf("������ϡ����������:");
	scanf("%d",&m);
	printf("\n������ϡ����������:");
	scanf("%d",&n);
	printf("\n������ϡ�����ķ���Ԫ�صĸ���:");
	scanf("%d",&t);
	s=m>n?m:n;//ȷ�������������е����ֵ 
	p=(crosslist *)malloc(sizeof(crosslist));
	p->row=m;
	p->col=n;
	head=p;
	cp[0]=p;//*cp[0....s]λһ��ָʾͷ�����У��б�ͷ����ָ�� 
	for(i=1;i<=s;i++)//����ͷ���ѭ������ 
	{
		p=(crosslist *)malloc(sizeof(crosslist));
		p->row=0;
		p->col=0;
		cp[i]=p;
		p->right=p;
		p->down=p;
		cp[i-1]->next=p;
	}
	cp[s]->next=head;
	for(k=0;k<t;k++)
	{
		printf("����һ������Ԫ�ص���Ԫ��(�ո����):\n");
		scanf("%d %d %d",&i,&j,&v);
		p=(crosslist *)malloc(sizeof(crosslist));
		p->row=i;
		p->col=j;
		p->value=v;
		q=cp[i];
		while((q->right!=cp[i])&&(q->down->col<j))
		{
			q=q->down;//���б���Ѱ���в���λ�� 
		}
		p->right=q->right;
		q->right=p;//��ɵ�i�в��� 
		q=cp[j];
		while((q->right!=cp[j])&&(q->down->row<i))
		{
			q=q->right;//���б���Ѱ���в���λ�� 
		}
		p->down=q->down;
		q->down=p;//��ɵ�j�в��� 
	}
	return head;
} 
int main()
{
	return 0;	
}