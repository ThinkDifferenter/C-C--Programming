#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h> 
#include <time.h> 

#define NSUM 25
#define W 128
#define K 8

#define C 429496729
#define T 100


//===============================³ÌĞòÉùÃ÷================================= 

void Reader_verify();
void Reader_base();
float O_distance(float *arr1, float *arr2);

void LSH(float *v, float H[K]);
void Match_test();
void Match_test2();
void K_random();