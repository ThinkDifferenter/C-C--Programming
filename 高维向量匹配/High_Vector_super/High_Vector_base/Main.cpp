#include "Head.h"

int main(int argc, char *argv[])
{
	int begintime;
	int endtime;
	begintime = clock();

	Process1();

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);

	system("pause");

	return 0;
}