#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE  20
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
int main()
{
	Array a=array_creat(10);
	printf("The array size is %d\n",array_size(&a));
	int number=0,cnt=0,i;
	printf("Please input number in array(-1 for quit):\n");
	while(number!=-1)
	{
		scanf("%d",&number);
		if(number!=-1)
		{
			*array_at(&a,cnt++)=number;
		}	
	}
	for(i=0;i<cnt;i++)
	{
		printf("%d\t",*array_at(&a,i));
	}
	return 0;
}
Array array_creat(int init_size)
{
	Array a;
	a.size=init_size;
	a.array=(int *)malloc(sizeof(int)*a.size);
	return a;
}

void array_free(Array *a)
{
	free(a->array);
	a->array=NULL;
	a->size=0;
	
}

int array_size(const Array *a)
{
	return a->size;
}

int* array_at(Array *a,int index)
{
	if(index>=a->size)
	{
		printf("array is overflowing!\n");
		array_inflat(a,BLOCK_SIZE);
	}
	return &(a->array[index]);
}

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