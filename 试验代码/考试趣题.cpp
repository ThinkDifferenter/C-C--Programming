//若有以下的定义和语句，则值为12的表达式是（    ）。
//struct wc{ int a；int *b；}*p；int x0[]={11，12}，x1[]={31，32}；
//static struct wc x[2]={100，x0，300，x1}； p=x；
//A *++p->b     B ++p->a      C p->b      D *(p++)->b
//前天考试中的一道题目,请你编程实现,并作仔细的研究,
//你会发现很多有趣的知识,将研究的结果写一个读书体会.
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
//初始化	static struct wc x[2]={100,x0,300,x1};
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