#include<stdio.h>
#define N 38
#define M 3.1415926 
int i=12;
int main()
{
	printf("sizeof (i)=%d\n",sizeof(i));
	printf("sizeof (N)=%d\n",sizeof(N));
	printf("sizeof (M)=%d\n",sizeof(M));
//	printf("the location of M is %d\n",&M);
//	printf("the location of N is %d\n",&N);
	printf("the location of i is %d\n",&i);
	//老师，我定义的无参数宏在内存有相应大小的存储块来存储它
	// 但是我对定义的宏进行取指运算，它给了我error说 no-lvalue in unary '&' 
	return 0;
}