#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE  20//一次增加20个单位的内存 

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
	printf("输入数据如下:\n");
	for(i=0;i<cnt;i++)
	{
		printf("第%d个数据为:%d\n",i+1,*array_at(&a,i));
	}
	printf("你想要更改哪个元素的数据:");
	scanf("%d",&index);
	printf("更改为:");
	scanf("%d",&n);
	array_set(&a,index-1,n);
	printf("更改后的第%d个数组元素为:%d\n",index,array_get(&a,index-1));
	return 0;
}
// 创建基础数组 
Array array_creat(int init_size)
{
	Array a;
	a.size=init_size;
	a.array=(int *)malloc(sizeof(int)*a.size);
	return a;
} 
//释放数组内存 
void array_free(Array *a)
{
	free(a->array);
	a->array=NULL;
	a->size=0;
	
}
//获取数组大小 
int array_size(const Array *a)//封装 
{
	return a->size;
}
//获取数组元素的下标 
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
//获取指定下标数组元素数据 
int array_get(const Array *a,int index)
{
	return a->array[index];
}
//更改指定下标元素数据 
void array_set(Array *a,int index,int value)
{
	a->array[index]=value;
}
//动态数组增长 
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
