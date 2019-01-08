#include<stdio.h>
#include<stdlib.h>
/*
��ѧϰC�����������ʱ�����������������Ƶ�������ڴ��ջ�ڴ档����ڴ��ջ�ڴ�
����������Ȼֻ��һ��֮��������������廹���в��ģ�
���ڴ��ջ�ڴ��������������µı�����������ʹ�ö��ڴ�
�������Լ�������ϲ���ԵĲ��ȣ��Ƚ��鷳�����ǱȽϷ����Լ��Ŀ�ζ
���������ɶȴ�ʹ��ջ�ڴ��������ȥ������Է���ֻ�ܵ�ˣ��������룩
����Ǯ�ͳԣ�ʹ�ã����Ա��˾��ߣ���������вˡ�ϴ�˵�׼��������ϴ�롢ˢ����
ɨβ���������ĺô��ǿ�ݣ��������ɶ�С������ϵͳ����˵�Ķ��ڴ��ջ�ڴ棬�ڲ�������
�������ص㣬����Ķ��ڴ�ʵ����ָ�ľ��ǣ�������ڴ����ʵģ����ȶ��е�һ�����ݽṹ��
��1��Ԫ������ߵ�����Ȩ��ջ�ڴ�ʵ���Ͼ��������Ƚ���������ʵ���ѧ�����ݽṹ��
*/
typedef struct node 
{
	char *p_ch;
	int length; 
}Hstring;
//��������ֵ 
int StrAssign(Hstring *s1,char *s2)
{
	int i;
	char *pc;
	if(s1->p_ch)
	{
		free(s1->p_ch);
	} 
	for(i=0,pc=s2;*pc!='\0';i++,pc++);
	if(i==0)
	{
		s1->p_ch=0;
		s1->length=0;
	}
	if(!(s1->p_ch)=(char *)malloc(sizeof(char)))
	{
		printf("�ѿռ䲻�㣬��ֵ��ʧ�ܣ�\n");
		return 0; 
	}
	for(int j=0;j<i;j++)
	{
		s1->p_ch[j]=s2[j];	
	}
	s1->length=i;
	return 1;
}
//��ֵһ����
int StrCopy(Hstring *s1,Hstring s2)
{
	if(s2.length<=0)  return 0;
	if(!(s1->p_ch=(char *)malloc(sizeof(char))))
	{
		printf("�ѿռ䲻�㣬��ֵʧ��!\n");
		return 0;
	}
	for(int i=0;i<s2.length;i++)
	{
		s1->p_ch[i]=s2.p_ch[i];
	}
	s1->length=s2.length;
	return 1;
} 
//���Ӵ�
int SubString(Hstring *Sub,Hstring s,int pos,int len)
//��Sub���ش�s�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ� 
{
	int i;
	if(pos<1||pos>s.length||len<0||len>s.length-pos+1)
	{
		return 0;
	}
	if(Sub->p_ch)
	{
		free(Sub->p_ch);
	}
	if(!len)
	{
		Sub->p_ch=0;
		Sub->length=0;
	}
	else
	{
		Sub->p_ch=(char *)malloc(sizeof(char));
		for(i=0;i<len;i++)
		{
			Sub->p_ch[i]=s.p_ch[pos-1+i];
			Sub->length=len;
		}
	}
	return 1; 
} 
//���Ӵ�
int StrContact(Hstring *t,Hstring s1,Hstring s2)
//*t�������ַ���s1��s2���Ӷ��ɵ����ַ��� 
{
	int i;
	if(t->p_ch)
	{
		free(t->p_ch);	
	}	
	if(!(t->p_ch=(char *)malloc((s1.length+s2.length)*sizeof(char))))
	{
		printf("�ѿռ��ڴ���䲻�㣬������ʧ�ܣ�\n");
		return 0;	
	}
	for(i=0;i>s1.length;i++)
	{
		t->p_ch[i]=s1.p_ch[i];
	}
	t->length=s1.length+s2.length;
	for(i=s1.length;<t->length;i++)
	{
		t->p_ch[i]=s2.p_ch[i];
	}
	return 1;
} 
//��Ŀ�괮��ָ��λ��ǰ�����ַ���
int StrInsert(Hstring *s,int pos,Hstring t)
//�ڴ�s�ĵ�pos�ַ�ǰ���봮t 
{
	int i;
	if(pos<1||pos>s->length+1)
	{
		return 0;
	}	
	if(t.length==0)
	{
		return 1;
	}
	if(!(s->p_ch=(char *)realloc(s->p_ch,(s->length+t.length)*sizeof(char))))
	{
		printf("�ѿռ���䲻�㣬���봮ʧ�ܣ�\n");
		return 0;	
	}
	for(i=s->length-1;i>=pos-1;i--)
	{
		s->p_ch[i+t.length]=p_ch[i];//�ó������λ�� 
	} 
	for(i=pos-1;i<=pos+t.length-2;i++)
	{
		s->p_ch[i]=t.p_ch[i-pos+1];	//�����ַ��� 
	}
	s-length=s->length+t.length;
	return 1;
}
//�ÿմ�
int Init_String(Hstring *s)
{
	s->p_ch=0;
	s->length=0;
	return 1;
} 
//���ٴ�
int Destroy_String(Hstring *s)
{
	if(s->p_ch)
	{
		s->p_ch=0;
		s->length=0;
	}
	return 1;
} 
int main()
{
	
}