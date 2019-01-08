#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE 20
typedef struct
{
	int *array;
	int size;
}Array;


Array array_creat(int init_size);
int array_size(const Array *a);
int * array_at(Array *a,int index);
void array_free(Array *a);
int array_inflat(Array *a,int more_size);

int main()
{
	Array a=array_creat(10);
	int number=0,cnt=0;
	printf("the size of array is %d\n",array_size(&a));
 	printf("Please input number to array:(-1 for quit)\n");
 	while(number!=-1)
 	{
	 	scanf("%d",&number);
	 	*(array_at(&a,cnt++))=number;
	 }
	 for(int i=0;i<cnt-1;i++)
	 {
 		printf("%d\t",*(array_at(&a,i)));
 	}
 	printf("\n");
 	return 0;
}

Array array_creat(int init_size)
{
	Array a;
	a.size=init_size;
	a.array=(int *)malloc(sizeof(int)*a.size);
	return a;
}

int array_size(const Array *a)
{
	return a->size;
}

int * array_at(Array *a,int index)
{
	if(a->size<=index)
	{
		printf("the array is overflowed!\n");
		array_inflat(a,BLOCK_SIZE);
	}
	return &(a->array[index]);
}

void array_free(Array *a)
{
	free(a->array);
	a->size=0;
	a->array=NULL;
}

int array_inflat(Array *a,int more_size)
{
	int *p=(int *)malloc(sizeof(int)*(a->size+more_size));
	for(int i=0;i<a->size;i++)
	{
		p[i]=a->array[i];
	}
	free(a->array);
	a->array=p;
	a->size+=more_size;
}

