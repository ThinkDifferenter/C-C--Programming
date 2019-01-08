#include<stdio.h> 
#include<stdlib.h>

main()
{
 int i,j,k,m,n,size;
 
 printf("input size:");
 scanf("%d",&size);
 
 if(size<=0||size%2==0)
 {
  printf("the size is error!\n");
  exit(-1);
 }
 
 for(i=1;i<=size;i++)
{
  n=(i<=(size/2)? i:size-i+1);
  n=2*n-1;
  m=(size-n)/2+15;
  for(k=1;k<=m;k++)
   printf(" ");
  for(j=1;j<=n;j++)
   printf("*");
  printf("\n");
  
 }
} 

