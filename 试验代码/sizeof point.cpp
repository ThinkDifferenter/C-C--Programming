#include<stdio.h>
int main()
{
	int i=100;
	int *p=&i;
	char *q;
	double *d;
	printf("sizeof (i)=%d\n",sizeof(i));
	printf("sizeof (P)=%d\n",sizeof(p));
	printf("sizeof (q)=%d\n",sizeof(q));
	printf("sizeof (d)=%d\n",sizeof(d));
	//�����Ҷ���ָ��ʲô���͵�ָ����������Ĵ�С����4���ֽ�
	//��ʦ���ǲ��Ǵ洢ָ����ڴ涼��4���ֽڰ��� 
	return 0;
}