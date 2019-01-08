#include <stdio.h>
main( )
{ int  v1= 0, v2 = 0; char ch;
  while(( ch=getchar())!='#')
switch(ch)
       { case  'a':
         case  'h':
         
         default: v1++;

         case 'o': v2++;  break;
     }
printf("v1= %d, v2 =%d\n", v1, v2);
}