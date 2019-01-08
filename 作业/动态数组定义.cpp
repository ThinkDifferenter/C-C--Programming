#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE  20//һ������20����λ���ڴ� 

typedef struct
{
	int *array;
	int size;
}Array;

Array array_creat(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a,int index);
void array_inflat(Array *a,int more_size);
int array_get(const Array *a,int index);
void array_set(Array *a,int index,int value);


int main()
{
	Array a=array_creat(10);
	printf("The array size is %d\n",array_size(&a));
	int number=0,cnt=0,i=0,n=0,index=0;
	printf("Please input number in array(-1 for qiut):\n");
	while(number!=-1)
	{
		scanf("%d",&number);
		if(number!=-1)
		{
			*array_at(&a,cnt++)=number;
		}	
	}
	//*array_at(&a,0)=10;
	//printf("%d\n",*array_at(&a,0));
	printf("������������:\n");
	for(i=0;i<cnt;i++)
	{
		printf("��%d������Ϊ:%d\n",i+1,*array_at(&a,i));
	}
	printf("����Ҫ�����ĸ�Ԫ�ص�����:");
	scanf("%d",&index);
	printf("����Ϊ:");
	scanf("%d",&n);
	array_set(&a,index-1,n);
	printf("���ĺ�ĵ�%d������Ԫ��Ϊ:%d\n",index,array_get(&a,index-1));
	return 0;
}
// ������������ 
Array array_creat(int init_size)
{
	Array a;
	a.size=init_size;
	a.array=(int *)malloc(sizeof(int)*a.size);
	return a;
} 
//�ͷ������ڴ� 
void array_free(Array *a)
{
	free(a->array);
	a->array=NULL;
	a->size=0;
	
}
//��ȡ�����С 
int array_size(const Array *a)//��װ 
{
	return a->size;
}
//��ȡ����Ԫ�ص��±� 
int* array_at(Array *a,int index)
{
	if(index>=a->size)
	{
		printf("array is overflowing!\n");
		array_inflat(a,BLOCK_SIZE);
		//array_inflat(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
	}
	return &(a->array[index]);
}
//��ȡָ���±�����Ԫ������ 
int array_get(const Array *a,int index)
{
	return a->array[index];
}
//����ָ���±�Ԫ������ 
void array_set(Array *a,int index,int value)
{
	a->array[index]=value;
}
//��̬�������� 
void array_inflat(Array *a,int more_size)
{
	int *p=(int *)malloc(sizeof(int)*(a->size+more_size));
	int i;
	for(i=0;i<a->size;i++)
	{
		p[i]=a->array[i];
	}
	free(a->array);
	a->array=p;
	a->size+=more_size;
}
