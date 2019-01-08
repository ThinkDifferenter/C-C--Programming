#include<stdio.h>
main()
{
	unsigned long NO;
	unsigned int year,month,day;
	unsigned char sex;
	float Chinese,Math,English;
	float total,average;
	
	printf("input student's NO:\n");
	scanf("%8ld",&NO);
	printf("input the student's Birthday(yyyy-mm-dd):\n");
	scanf("%4d-%2d-%2d",&year,&month,&day);
	fflush(stdin);
	printf("input the student's Sex(M=1/F=2)\n");
	scanf("%d",&sex);
	printf("input the student's Scores(Chinese,Math,English):\n");
	scanf("%f %f %f",&Chinese,&Math,&English);
	
	
	
	total=Chinese+Math+English;
	average=total/3;
	printf("\n===NO=======Birthday==sex===Chinese==Math===English===total==averge\n");
	printf("%8ld   %4d-%2d-%2d  %c   %-5.1f   %-5.1f   %-5.1f   %-5.1f   %-5.1f\n",
	NO,year,month,day,sex,Chinese,Math,English,total,average);
	
}
