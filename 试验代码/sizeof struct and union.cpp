#include<stdio.h>
struct student
{
	int num;
	double score;
};

union Student{
	int num;
	double score;
};

int main()
{
	printf("the sizeof struct is %d\n",sizeof(student));
	printf("the sizeof union is %d\n",sizeof(Student));
	return 0;	
}