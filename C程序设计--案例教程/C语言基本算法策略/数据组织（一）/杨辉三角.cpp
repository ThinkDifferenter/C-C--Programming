#include <stdio.h>  
 
void print_triangle(int* a, int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
int main()
{
    int i, j, N;
    int a[100] = { 1, 0 };
    int old, s;
    printf("Input the number of line:");
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        old = a[0];
        for (j = 0; j < i; j++)
        {
            s = old;
            old = a[j + 1];
            a[j + 1] = s + old;
        }
        print_triangle(a, i);
    }
    return 0;
}