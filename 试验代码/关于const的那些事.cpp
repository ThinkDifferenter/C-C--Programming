#include<stdio.h>
int main()
{
	int i=3;
	int j=4;
	int k=5;
	const int *p=&i;//*p所指向的整型数据i被const了！
	//i++  erorr!
	p=&k; //right!
	int const *q=&j;//指向j的指针被const了！
	//q=&k; erorr!
	j++; //right!
	return 0;
}