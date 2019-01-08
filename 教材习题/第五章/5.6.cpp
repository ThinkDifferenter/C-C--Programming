#include<stdio.h>
int main()
{
	double score;
	printf("input your score (1~100):");
	scanf("%lf",&score);
	
	if(score>=90)
	{
		printf("you get A!\n");
	}
	else if(score>=80&&score<=89)
	{
		printf("you get B!\n");
	}
	else if(score>=70&&score<=79)
	{
		printf("you get C!\n");
	}
	else if(score>=60&&score<=69)
	{
		printf("you get D!\n");
	}
	else if(score<60)
	{
		printf("you get E!\n");
	}
	return 0;
}