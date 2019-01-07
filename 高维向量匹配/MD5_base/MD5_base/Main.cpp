#include "Head.h"

int main(int argc, char *argv[])
{
	int begintime;
	int endtime;
	begintime = clock();

	Process();
	
	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);
	return 0;
}