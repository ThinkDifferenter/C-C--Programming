//�������µĶ������䣬��ֵΪ12�ı��ʽ�ǣ�    ����
//struct wc{ int a��int *b��}*p��int x0[]={11��12}��x1[]={31��32}��
//static struct wc x[2]={100��x0��300��x1}�� p=x��
//A *++p->b     B ++p->a      C p->b      D *(p++)->b
//ǰ�쿼���е�һ����Ŀ,������ʵ��,������ϸ���о�,
//��ᷢ�ֺܶ���Ȥ��֪ʶ,���о��Ľ��дһ���������.
#include<stdio.h>
struct wc
{
	int a;
	int *b;
}*p;
int main()
{
	int x0[]={11,12};
	int x1[]={31,32};
	static struct wc x[2]={{100,x0},{300,x1}};
//��ʼ��	static struct wc x[2]={100,x0,300,x1};
	p=x;
	int i=0;
	printf("1.Show *(++p)->b:\n");// 31
	printf("2.Show *++p->b:\n");//12
	printf("3.Show *(p++)->b:\n");//11
	printf("4.Show *p++->b:\n");//11
	printf("5.Show *p->b\n");//11
	printf("Choose output:");
	scanf("%d",&i);
	switch(i)
	{
		case 1 :
				printf("location 1:%p\n",p);
				printf("%d\n",*(++p)->b);
				printf("location 2:%p\n",p);
	 			break;
		case 2 :
				printf("location 1:%p\n",p);
				printf("%d\n",*++p->b);   
				printf("location 2:%p\n",p);
				break;
		case 3 :
				printf("location 1:%p\n",p);
				printf("%d\n",*(p++)->b);
				printf("location 2:%p\n",p);
			 	break;
		case 4 :
				printf("location 1:%p\n",p);
				printf("%d\n",*p++->b);   
				printf("location 2:%p\n",p);
				break; 
		case 5 :
				printf("location 1:%p\n",p);
				printf("%d\n",*p->b);   
				printf("location 2:%p\n",p);
				break; 		
	}
	return 0;
}