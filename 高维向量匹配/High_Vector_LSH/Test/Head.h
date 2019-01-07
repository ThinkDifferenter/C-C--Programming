 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h> 
#include <time.h> 

#define NSUM 25
#define W 4
#define K 8
#define C 429496729
#define T 100

void a_Random(float gs[], int lengh);
float Gaussrand();
float b_Random(int min, int max);

void Process1();
void Reader_base();

void LSH(float *v, float H[K]);

void Random_make();
void k_Random();

float Hash_1(float H[K]);
float Hash_2(float H[K]);

void newdata();
void Match_test();