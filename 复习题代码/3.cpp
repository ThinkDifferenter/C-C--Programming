  #include <stdio.h>
   int main()
{
   int s[4][4],i,j,k;
   for(i=0;i<4;i++)
     for(j=0;j<4;j++)
      s[i][j]=i-j;
    for(i=0;i<3;i++)
     for(j=i+1;j<4;j++)
       { k=s[i][j];
         s[i][j]=s[j][i];
		s[j][i]=k;
}
          for(i=0;i<4;i++)
{
  for(j=0;j<4;j++)
    printf("%5d",s[i][j]);
 printf("\n");
}
return 0;
       }