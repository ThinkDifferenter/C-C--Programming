#include<stdio.h>
main()
{int a=0,b=0,c=0;
 
printf("������������;\n");
scanf("%a %b %c",&a,&b,&c);

int max=0;

if(a>b)
{
	if(a>c){max=a;}
	else{max=c;} 
}
else
{
	if(b>c){max=b;}
	else{max=c;}
}

printf("�������ǣ�%d",max);
return 0;

}
