#include<stdio.h>
int main()
{
	int i=3;
	int j=4;
	int k=5;
	const int *p=&i;//*p��ָ�����������i��const�ˣ�
	//i++  erorr!
	p=&k; //right!
	int const *q=&j;//ָ��j��ָ�뱻const�ˣ�
	//q=&k; erorr!
	j++; //right!
	return 0;
}