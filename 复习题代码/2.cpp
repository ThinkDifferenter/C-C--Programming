 #include <stdio.h>
   int main()
    { int y£»
     int fac(int,int);
     fac(4,&y);
     printf("y=%d\n",y);
     return 0;
    }
   int  fac(int n,int *t)
    {  int s;
       if((n==1)||(n==0))  
		*t=1;
       else  
{  fac(n-1,&s);  t=n*s; }
    }