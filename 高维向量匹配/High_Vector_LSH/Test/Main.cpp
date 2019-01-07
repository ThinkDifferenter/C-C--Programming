#include "Head.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int begintime;
	int endtime;
	begintime = clock();
	

	 
	
	//Random_make();
	//k_Random();
	//Process1();
	Match_test();

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);
	system("pause");

	return 0;
}