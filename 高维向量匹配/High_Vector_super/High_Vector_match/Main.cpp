#include "Head.h"

int main(int argc, char *argv[])
{
	//开始计时
	int begintime;
	int endtime;
	begintime = clock();

	//开始匹配
	Match();

	//结束计时并输出
	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);
	system("pause");

	return 0;
}