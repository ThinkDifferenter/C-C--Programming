#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 
    struct person
         {
	       char name[15];
	       char sex[2];
           int nianling;
           long int youbian;
	       char addr[50];
	       char celephone[22];
	       char homephone[22];
       	   char company[20];
	       char email[40];
	       long int QQ;
        }per[500];
   int num=0;//*�ⲿ����numΪ�ļ��еļ�¼��*//
   FILE *fp; 
   void mainmenu();//*���˵�*//
   void newrecord();//�����¼*//
   
   void xiugaimenu();//*�޸Ĳ˵�*//
   void xiugaibyname();//*�������޸�*//
   void xiugaibycelephone();//*���ֻ������޸�*//
   void xiugaixiangmu(int a);//*�޸���Ŀ*//
   
   void searchmenu();//*��ѯ�˵�*// 
   void searchbyname();//*��������ѯ*//
   void searchbycelephone();//*���ֻ������ѯ*//
   void searchbyhomephone();//*����ͥ�绰�����ѯ*//
   void searchbyqq();//*��QQ��ѯ*//
   
   void deletemenu();//*ɾ���˵�*//
   void deleteall();//*ɾ�������� Ϣ*// 
   void deleteone();//*ɾ������*//
   
   void showall();//*�� �� ȫ �� �� Ϣ*// 
   
   void readfromfile();//*��ȡ�ļ�*// 
   void writetofile();//*д���ļ�*// /
   
   void deletebycelephone();  //*���ֻ�����ɾ��*//
   void deletebyname();//*������ɾ��*/ 
   
   void listbycelephone();//*���ֻ���������*// 
   void listbyname();//*����������*// 
   void listmenu();//*����˵�*// 
   


int main()//*������*// 
{ 
	system("cls");
	readfromfile(); 
	while (1) 
	{ 
		mainmenu(); 
	} 
	return 0;
} //*����������*//





void mainmenu()//*���˵�����*// 
{ 
	int a; 
	system("cls"); 
	system("color 2a");//shell ��ɫ������� 
	printf("\n\t  �� ��! �� ӭ ʹ �� ͨ Ѷ ¼!\n");
	printf("             1: �� �� �� �� �� Ϣ\n");
	printf("             2: �� ѯ �� �� �� Ϣ\n");
	printf("             3: ɾ �� �� �� �� Ϣ\n");
	printf("             4: �� �� �� �� �� Ϣ\n");
	printf("             5: �� Ϣ �� ��\n");
	printf("             6: �� �� ȫ �� �� Ϣ\n");
	printf("             7: д �� �� ��\n");
	printf("             8: �� ȡ �� ��\n");
	printf("             9: ɾ������\n");
	printf("             0: �� ��  \n");
	printf("          ��������������ѡ��:    ");
	loop1: scanf("%d",&a); 
	switch (a) 
	{

		case 1:newrecord();break; 
		case 2:searchmenu();break; 
		case 3:deletemenu();break; 
		case 4:xiugaimenu();break;
		case 5:listmenu();break;
		case 6:showall();break;
		case 7:writetofile();break; 
		case 8:readfromfile();break;
		case 9:deleteall();break;
		case 0:exit(0); 
		default:printf("�Բ�������������������������:   ");goto loop1; 
	} 
} 


void newrecord()//*��Ӽ�¼*// 
{
     int a; 
     system("cls"); 
     system("color 2a"); 
loop:	  printf("\n\n\n\n\t\t  ��������Ҫ��ӵ���ϵ�˵���Ϣ�� \n"); 	
  	  printf("\n����������:\n");
name: scanf("%s",&per[num].name);
	  if(strlen(per[num].name)>15)
	   {
		  printf("�Բ�������������������������");
		  goto name;
	   }
      printf("\n�������Ա�:\n");
sex:  scanf("%s",&per[num].sex);
	  if(strlen(per[num].sex)==0)
	  {
	     printf("�Բ�������������������������");
	     goto sex;
	  }
	  printf("\n����������:");
nianling:  	scanf("%d",&per[num].nianling); 
      if(per[num].nianling<10||per[num].nianling>110)
       {
       	  printf("�Բ�������������������������");
       	  goto  nianling;
       }
      printf("\n�������ʱ�\n");
youbian:    scanf("%d",&per[num].youbian); 
      if(per[num].youbian<10000||per[num].youbian>999999) 
	  {
	      printf("�Բ�������������������������");
		  goto  youbian;
	  }
	  printf("\n�������ַ\n");
addr:	scanf("%s",&per[num].addr);
	  if(strlen(per[num].addr)>50||strlen(per[num].addr)<4)
	  {
		  printf("�Բ�������������������������\n");
		  goto addr;
	  }
	  printf("\n�������ֻ�����:\n"); 
celephone:   scanf("%s",&per[num].celephone);
	  if(strlen(per[num].celephone)!=11) 
	  {
		  printf("�Բ�������������������������\n");
		  goto celephone;
	  }	  
	  printf("\n�������ͥ�绰����:\n");
homephone:	scanf("%s",&per[num].homephone);
	  if(strlen(per[num].homephone)!=11)
	     {
		    printf("�Բ�������������������������\n");
		    goto homephone;
	     }
	  printf("\n�����빫˾����:");
company:    scanf("%s",&per[num].company);
	if(strlen(per[num].company)>20||strlen(per[num].company)<10)
	  {
		  printf("�Բ�������������������������");
		  goto company;
	  }
	  printf("\n�����������:"); 
email:	scanf("%s",&per[num].email); 
	if(strlen(per[num].email)>30||strlen(per[num].email)<4)
	  {
		  printf("�Բ�������������������������");
		  goto email;
	  }
	printf("\n����QQ����:");
QQ:	scanf("%ld",&per[num].QQ);
	if(per[num].QQ>1600000000||per[num].QQ<10000000)
	  {
		  printf("�Բ�������������������������");
		  goto QQ;
	  }
	num++; 
	printf("\n�Ƿ�������?\n"); 
	printf("\n�밴1��2��1���������2����������\n");
    printf("����������ѡ��  ");
    scanf("%d",&a);
    if(a==1)
    {
	  goto loop;
    }
    else
    {
	   return;
    }
} 




void searchmenu()//*��ѯ�˵�*// 
{ 
	int a; 
	system("cls");
	system("color 2a"); 
	printf("\n\t\t  ��   ӭ   ʹ    ��    ��    ѯ    ��   ��"); 
	printf("\n\t\t           1-���ֻ������ѯ");
	printf("\n\t\t           2-��������ѯ");
	printf("\n\t\t           3-����ͥ�绰�����ѯ"); 
	printf("\n\t\t           4-��QQ��ѯ"); 
    printf("\n\t\t           5-�������˵�"); 
	printf("\n\t\t"); 
    printf("����������ѡ��  ");
	scanf("%d",&a); 
	switch (a) 
	{  
		case 1:searchbycelephone();break; 
		case 2:searchbyname();break; 
		case 3:searchbyhomephone();break;
		case 4:searchbyqq();break;	
		case 5:mainmenu();break; 
	} 
} 


void searchbycelephone()//*���ֻ������ѯ*// 
{ 
	int mark=0; 
	int i,j; 
	int a=0; 
	char celephone[11]; 
	printf("\n               ���ֻ��������                \n"); 
	printf("\n�������ֻ�����:\n"); 
	scanf("%s",celephone); 
	for(i=0;i<num;i++) 
	{ 
		if (strcmp(per[i].celephone,celephone)==0) 
		{ 
			printf("\n                 �����������ҵ���ϵ�˵���Ϣ        "); 
			printf("\n________________________________"); 
			printf("\n���֣� %s",per[i].name); 
			printf("\n�Ա� %s",per[i].sex); 
			printf("\n���䣺 %d",per[i].nianling); 
			printf("\n�ʱ� �� %ld",per[i].youbian);
			printf("\n��ַ�� %s",per[i].addr);
			printf("\n�ֻ����룺 %s",per[i].celephone);
			printf("\n��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n��˾���ƣ�%s",per[i].company);
			printf("\n�����ʼ���%s",per[i].email);
			printf("\nQQ���룺%ld",per[i].QQ);
			printf("\n________________________________"); 
		    printf("\n�밴�������ּ��������˵�"); 
		    mark++;
		    scanf("%d",&j); 
		    return; 
		} 
	} 
	if (mark==0) 
	{ 
		printf("\n�Բ���!û�и���ϵ�˵���Ϣ!"); 
		printf("\n�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return; 
	} 
}



void searchbyname()//*��������ѯ*// 
{ 
	int mark=0; 
	int i,j,findmark=0; 
	int a=0;
	char name[15]; 
	printf("\n                  ����������                  "); 
	printf("\n����������:"); 
	scanf("%s",name); 
	for(i=a;i<num;i++) 
	{ 
		if (strcmp(per[i].name,name)==0) 
		{ 
            findmark++;
			printf("\n\t\t               �����������ҵ���ϵ�˵���Ϣ            "); 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
			if ((i+1)<num) 
			{ 
				printf("\n�Ƿ����������ͬ���ֵ���ϵ�˵���Ϣ?��1���������2����������"); 
				scanf("%d",&j);
				if (j==1) 
				{ 
					a=i; 
                    mark++;
					continue; 
				} 
				else 
					break; 
			} 
			else
			{
                 printf("\n�밴�������ּ��������˵�"); 
		         scanf("%d",&j); 
		         return; 
			}
		} 
	} 
	if(mark!=0) 
	{ 
		printf("\n�Բ���! û����ͬ���ֵĸ���ϵ�˵���Ϣ!��"); 
		printf("\n�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return; 
	} 
	else if(findmark==0) 
	{ 
		printf("\n�Բ���!û�и���ϵ�˵���Ϣ!"); 
		printf("\n�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return;  
	} 
} 



void searchbyhomephone()//*����ͥ�绰�����ѯ*// 
{ 
	int mark=0; 
	int i,j; 
	int a=0;
	char homephone[11]; 
	printf("\n\t\t                   ����ͥ�绰�������                     "); 
	printf("\n�������ͥ�绰����:"); 
	scanf("%s",homephone); 
	for(i=0;i<num;i++) 
	{ 
		if (strcmp(per[i].homephone,homephone)==0) 
		{ 
			printf("\n\t\t                ��������Ҫ���ҵ���ϵ�˵���Ϣ          "); 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
            printf("\n\t\t�밴�������ּ��������˵�");
			mark++; 
		    scanf("%d",&j); 
		    return; 
		} 
	} 
	if (mark==0) 
	{ 
		printf("\n\t\t�Բ���!û�и���ϵ�˵���Ϣ!"); 
		printf("\n\t\t�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return;  
	} 
} 



void searchbyqq()//*��QQ��ѯ*// 
{ 
	int mark=0; 
	int i,j; 
	long int QQ; 
	printf("\n\t\t                     ��QQ�������                      \n"); 
	printf("\n������QQ����:"); 
	scanf("%ld",&QQ); 
	for(i=0;i<num;i++) 
	{ 
		if(per[i].QQ==QQ) 
		{ 
			printf("\n\t\t                 �����������ҵ���ϵ�˵���Ϣ           "); 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
		    printf("\n\t\t�밴�������ּ��������˵�"); 
		    mark++;
		    scanf("%d",&j); 
		    return; 
		} 
	} 
	if (mark==0) 
	{ 
		printf("\n\t\t�Բ���!û�и���ϵ�˵���Ϣ!"); 
		printf("\n\t\t�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return; 
	} 
} 



 
void deletemenu()//*ɾ���˵�*// 
{  
    int i,j;
    system("cls");
	system("color 3b");   
	if(num==0) 
	{ 
		printf("\n\t\t�Բ���!�ļ������κμ�¼!");
		printf("\n\t\t������Ӹ�����Ϣ!");
		printf("\n\t\t�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return; 
	} 
	else
	{
	   printf("\n\t\t                   ɾ �� �� ��                   "); 
       printf("\n\t\t                   1-ɾ������                    ");	
	   printf("\n\t\t                  2-�������˵�                   "); 
	   printf("\n\t\t                                                 "); 
	   printf("\n\t\t��������������ѡ��:    "); 
	   loop4: scanf("%d",&i); 
	   switch (i) 
	   { 
		case 1:deleteone();break; 
		case 2:mainmenu();break; 
		default:printf("�Բ�������������������������:   ");goto loop4; 
	   }
	}
} 



void deleteone()//*ɾ������*//
{ 
	int i; 
	printf("\n\t\t1-���ֻ�����ɾ�� 2-������ɾ��"); 
	printf("\n\t\t����������ѡ��"); 
	loop5:scanf("%d",&i);; 
	switch (i) 
	{ 
	case 1:deletebycelephone();break; 
	case 2:deletebyname();break;
    default:printf("�Բ�������������������������:   ");goto loop5; 
	} 
}


void deletebyname()//����ɾ��*// 
{ 
	int a=0; 
	int findmark=0; 
	int i,j,k; 
	int deletemark=0; 
	char name[15]; 
	printf("\n\t\t��������Ҫɾ������ϵ�˵�������"); 
	scanf("%s",name); 
	for (i=a;i<num;i++) 
	{ 
		if (strcmp(per[i].name,name)==0) 
		{ 
			printf("\n\t\t��������Ҫɾ������ϵ�˵ļ�¼��"); 
			findmark++; 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
			printf("\n\t\t�Ƿ�ɾ��?��1����ɾ����2����ɾ����\n");
			printf("\n\t\t��������������ѡ��:    "); 
			scanf("%d",&k); 
			if(k==1) 
			{ 
				for (j=i;j<num-1;j++) //*��¼�ƶ�����per������ɾ��֮*// 
				per[j]=per[j+1]; 
				num--; 
				deletemark++; 
				printf("\n\t\tɾ���ɹ�"); 
				if((i+1)<num) 
				{ 
					printf("\n\t\t�Ƿ����ɾ����ͬ��������ϵ�˵���Ϣ?��1����ɾ����2����ɾ����"); 
			        printf("\n\t\t��������������ѡ��:    "); 
			        scanf("%d",&k); 
			        if(k=1)
					{ 
						a=i; 
						findmark++;
						continue; 
					} 
				} 
				printf("\n\t\t�Ƿ����ɾ��?��1���������2����������"); 
                printf("\n\t\t��������������ѡ��:    "); 
                scanf("%d",&k);
                if(k==1)
				   deleteone(); 
				else
				break; 
			} 
		}	
		else 
		continue; 
	} 
	if((deletemark==0)&&(findmark==0)) 
	{ 
		printf("\n\t\t�Բ���!û�и���ϵ�˵ļ�¼!"); 
		printf("\n\t\t�Ƿ����ɾ��?��1���������2����������"); 
		printf("          ��������������ѡ��:    ");
		scanf("%d",&k);
		if(k==1)  
		  deleteone(); 

	} 
	else if(findmark!=0) 
	{ 
		printf("\n\t\t�Բ���!û��������Ϣ!"); 
		printf("\n\t\t�Ƿ����ɾ��?��1���������2����������"); 
		printf("          ��������������ѡ��:    ");
		scanf("%d",&k);
	    if(k==1) 
		   deleteone(); 
	} 
} 


void deletebycelephone()//*���ֻ�����ɾ��*// 
{ 
	int i,j,h,m; 
	int deletemark=0; 
	char celephone[11]; 
	printf("\n\t\t������Ҫɾ������ϵ�˵��ֻ����룺"); 
	scanf("%s",celephone); 
	for(i=0;i<num;i++) 
	{ 
		if(strcmp(per[i].celephone,celephone)==0) 
		{ 
		    deletemark++;
			printf("\n\t\t��������Ҫɾ������ϵ�˵ļ�¼��");
			printf("\n\t\t________________________________"); 		 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
			printf("\n\t\t�Ƿ�ɾ��?��1����ɾ����2����ɾ����\n"); 
			printf("          ��������������ѡ��:    ");
			scanf("%d",&h);
	        if(h==1) 
			{ 
				for (j=i;j<num-1;j++) /*��¼�ƶ�����per������ɾ��֮*/ 
				per[j]=per[j+1]; 
				num--;  
				printf("\n\t\tɾ���ɹ�"); 
				printf("\n�Ƿ����ɾ��?��1���������2����������\n"); 
				printf("          ��������������ѡ��:    ");
				scanf("%d",&h);
	            if(h==1)  
				     deletebycelephone(); 
			} 
		} 
	} 
	if(deletemark==0) 
	{ 
		printf("\n\t\t�Բ���!û�и���ϵ�˵ļ�¼!"); 
		printf("\n\t\t�Ƿ����ɾ��?��1���������2����������\n"); 
		printf("          ��������������ѡ��:    ");
		scanf("%d",&m);
	    if(m==1)  
		   deletebycelephone();
	}
} 



void xiugaimenu()//*�޸Ĳ˵�*//
{
	int i,j;
    system("cls");
	system("color 3f");
	if(num==0) 
	{ 
		printf("\n\t\t�Բ���!�ļ������κμ�¼!"); 
		printf("\n\t\t�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return;  
	}
	else
	{ 
	    printf("\n\t\t 1-�������޸�   2-���ֻ������޸�\n"); 
	    printf("          ��������������ѡ��:    ");
	loop6:scanf("%d",&i);
	    switch (i) 
	    { 
	      case 1:xiugaibyname();break; 
	      case 2:xiugaibycelephone();break; 
	      default:printf("�Բ�������������������������:   ");goto loop6;
	    } 
	}
}



void xiugaibyname()//*�������޸�*//
{
	int a=0; 
	int findmark=0; 
	int xiugaimark=0; 
	int i,j; 
	char name[15]; 
	printf("\n\t\t������Ҫ�޸���ϵ�˵�������"); 
	scanf("%s",name); 
	for (i=a;i<num;i++) 
	{ 
		if (strcmp(per[i].name,name)==0) 
		{ 
			printf("\n\t\t��������Ҫ�޸ĵ���ϵ�˵ļ�¼��"); 
			findmark++; 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________");
			printf("\n\t\t�Ƿ��޸�?��1�����޸ģ�2�����޸ģ�"); 
			printf("          ��������������ѡ��:    ");
			scanf("%d",&j);
			if (j==1) 
			{ 
				xiugaixiangmu(i);
				xiugaimark++; 
				printf("\n\t\t�޸ĳɹ�"); 
				if((i+1)<num) 
				{ 
					printf("\n\t\t�Ƿ�����޸���ͬ��������ϵ�˵���Ϣ?��1���������2����������"); 
					printf("          ��������������ѡ��:    ");
					scanf("%d",&j);
					if (j==1) 
					{ 
						a=i;
						findmark++; 
						continue; 
					} 
				} 
				printf("\n\t\t�Ƿ�����޸�?��1���������2����������"); 
				printf("          ��������������ѡ��:    ");
				scanf("%d",&j);
				if (j==1) 
				xiugaibyname(); 
				return; 
			} 
		}
	}
	if ((xiugaimark==0)&&(findmark==0)) 
	{ 
		printf("\n\t\tû�и���ϵ�˵ļ�¼"); 
		printf("\n\t\t�Ƿ�����޸�?��1���������2����������"); 
		printf("          ��������������ѡ��:    ");
		scanf("%d",&j);
		if (j==1) 
		    xiugaibyname(); 
		return; 
	}
	else if (findmark!=0) 
	{ 
		printf("\n\t\tû��������Ϣ"); 
		printf("\n\t\t�Ƿ�����޸�?��1���������2����������"); 
		printf("          ��������������ѡ��:    ");
		scanf("%d",&j);
		if (j==1) 
		xiugaibyname(); 
		return; 
	} 
}



void xiugaibycelephone()//*���ֻ������޸�*//
{
	int findmark=0; 
	int i,j; 
	char celephone[11]; 
	printf("\n\t\t������Ҫ�޸���ϵ�˵��ֻ����룺"); 
	scanf("%s",celephone); 
	for (i=0;i<num;i++) 
	{ 
		if (strcmp(per[i].celephone,celephone)==0) 
		{ 
			printf("\n\t\t��������Ҫ�޸ĵ���ϵ�˵ļ�¼��"); 
			findmark++; 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________");
			printf("\n\t\t�Ƿ��޸�?��1�����޸ģ�2�����޸ģ�"); 
			printf("          ��������������ѡ��:    ");
			scanf("%d",&j);
		    if (j==1) 
			 {
				xiugaixiangmu(i);
				printf("\n\t\t�޸ĳɹ�"); 
				printf("\n\t\t�Ƿ�����޸�?��1���������2����������"); 
				printf("          ��������������ѡ��:    ");
				scanf("%d",&j);
		        printf("          ��������������ѡ��:    ");
				if (j==1)  
				  xiugaixiangmu(i); 
				break; 
			 } 
		}  
	} 
	if (findmark==0) 
	{ 
		printf("\n\t\t�Բ���!û�и���ϵ�˵ļ�¼!"); 
		printf("\n\t\t�Ƿ�����޸�?��1���������2����������"); 
		printf("          ��������������ѡ��:    ");
		scanf("%d",&j);
		if (j==1)  
		   xiugaibycelephone(); 
		return; 
	} 
}



void xiugaixiangmu(int a)//*�޸���Ŀ*//
{
	int i;
	system("cls"); 
	system("color c0");
	printf("\n\t\t             ��������Ҫ�޸ĵ���Ŀ               ");
	printf("\n\t\t\n");
	printf("\n\t\t1-�ֻ�����\n");
	printf("\n\t\t2-����\n");
	printf("\n\t\t3-��ͥ�绰����\n"); 
	printf("\n\t\t4-QQ����\n");
	printf("\n\t\t5-��ַ\n");
	printf("\n\t\t6-�ʱ�\n");
	printf("\n\t\t7-�����ʼ�\n");
	printf("\n\t\t8-�����˵�\n"); 
	printf("\n\t\t\n"); 
	printf("          ��������������ѡ��:    ");
	scanf("%d",&i);
loop9:	switch (i) 
	{

		case 1:printf("�������ֻ����룺");
			scanf("%s",&per[a].celephone);break;
		case 2:printf("������������");
			scanf("%s",&per[a].name);break;
		case 3:printf("�������ͥ�绰���룺");
			scanf("%s",&per[a].homephone);break;
		case 4:printf("������QQ���룺");
			scanf("%s",&per[a].QQ);break;
		case 5:printf("�������ַ��");
			scanf("%s",&per[a].addr);break;
		case 6:printf("�������ʱࣺ");
			scanf("%s",&per[a].youbian);break;
		case 7:printf("������email��");
			scanf("%s",&per[a].email);break;
		case 8:mainmenu();break;
		default: printf("�Բ�������������������������:   ");goto loop9;
	}
}


void listmenu()//*����˵�*//
{ 
    int i,j;
    system("cls");
	system("color b0");
	if(num==0) 
	{ 
		printf("\n\t\t�Բ����ļ������κμ�¼"); 
		printf("\n\t\t�밴�������ּ��������˵�"); 
		scanf("%d",&j); 
		return;  
	} 
	else
	{
	   system("cls");
	   system("color 12");
	   printf("\n\t\t              ��   ��   ��   ��                 "); 
	   printf("\n\t\t                 1-����������                   ");
	   printf("\n\t\t                 2-���ֻ���������                   "); 
	   printf("\n\t\t                 3-�������˵�                   "); 
       printf("                 ��������������ѡ��:    ");
loop10:		scanf("%d",&i); 
	   switch(i) 
	   { 
		 case 1:listbyname();break; 
		 case 2:listbycelephone();break; 
		 case 3:mainmenu();break; 
		 default:printf("�Բ�������������������������:   ");goto loop10; 
	   } 
	}
}


void listbyname()//*����������*// 
{ 
	int i,j,k; 
	struct person tmp; 
	for (i=1;i<num;i++) 
	{ 
		if(strcmp(per[i].name,per[i-1].name)<0) 
		{ 
			tmp=per[i]; 
			j=i-1; 
			do 
			{ 
				per[j+1]=per[j]; 
				j--; 
			}
			while ((strcmp(tmp.name,per[j].name)<0&&j>=0)); 
			per[j+1]=tmp; 
		} 
	} 
	    printf("\n\t\t����ɹ�,�Ƿ���ʾ?��1���������2����������"); 
		printf("          ��������������ѡ��:    ");
		scanf("%d",&k);
		if (k==1)   
		   showall(); 
	    return; 
} 


void listbycelephone()//*���ֻ���������*// 
{ 
	int i,j,k; 
	struct person tmp; 
	for (i=1;i<num;i++) 
	{ 
		if(strcmp(per[i].celephone,per[i-1].celephone)<0) 
		{ 
			tmp=per[i]; 
			j=i-1; 
			do 
			{ 
				per[j+1]=per[j]; 
				j--; 
			}while ((strcmp(tmp.celephone,per[j].celephone)<0)&&j>=0); 
			per[j+1]=tmp; 
		} 
	} 
	printf("\n\t\t����ɹ�,�Ƿ���ʾ?��1���������2����������"); 
	printf("          ��������������ѡ��:    ");
	scanf("%d",&k);
	if (k==1) 
	   showall(); 
	return; 
}








void showall()//*�� �� ȫ �� �� Ϣ*// 
{ 
	int i,j; 
	system("cls");
	system("color 3b"); 
	if(num!=0) 
	{ 
		printf("\n\t\t*************** ����ΪͨѶ¼������Ϣ************"); 
		for (i=0;i<num;i++) 
		{ 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t���֣� %s",per[i].name); 
			printf("\n\t\t�Ա� %s",per[i].sex); 
			printf("\n\t\t���䣺 %d",per[i].nianling); 
			printf("\n\t\t�ʱ� �� %ld",per[i].youbian);
			printf("\n\t\t��ַ�� %s",per[i].addr);
			printf("\n\t\t�ֻ����룺 %s",per[i].celephone);
			printf("\n\t\t��ͥ�绰���룺%s",per[i].homephone); 
			printf("\n\t\t��˾���ƣ�%s",per[i].company);
			printf("\n\t\t�����ʼ���%s",per[i].email);
			printf("\n\t\tQQ���룺%ld",per[i].QQ);
			printf("\n\t\t________________________________");
			printf("\t\t"); 
			if (i+1<num) 
			{ 
				printf("\n\t\t__________________________"); 
				system("pause"); 
			} 
		}	 
		printf("\n\t\t************************************************"); 
	} 
	else 
	   printf("\n\t\t�Բ���!ͨѶ¼�����κμ�¼!"); 
	printf("\n\t\t�밴�������ּ��������˵�"); 
	scanf("%d",&j); 
	return;  
} 




void writetofile()//*д���ļ�*// 
{ 
	int i,k;
	system("cls"); 
	system("color 84");
	if ((fp=fopen("per.bin","wb"))==NULL) 
	{ 
		printf("\n\t\t�ļ���ʧ��"); 
	} 
	for (i=0;i<num;i++) 
	{ 
		if (fwrite(&per[i],sizeof(struct person),1,fp)!=1) 
		{ 
			printf("\n\t\tд���ļ�����!\n"); 
		} 
	} 
	fclose(fp); 
	printf("\n\t\tͨѶ¼�ļ��ѱ���"); 
	printf("\n\t\t�밴�������ּ��������˵�"); 
	scanf("%d",&k); 
	return; 
} 

 





void readfromfile()//*��ȡ�ļ�*// 
{ 
    int i,j,k;
    system("cls"); 
	system("color 2b");
	if((fp=fopen("per.bin","rb"))==NULL) 
	{ 
		printf("\n\t\t****************************");
		printf("\n\t\t*                          *");
		printf("\n\t\t*                          *");
		printf("\n\t\t*    ͨѶ¼�ļ�������!     *"); 
		if ((fp=fopen("per.bin","wb"))==NULL) 
		{ 
			printf("\n*        ����ʧ��!         *");
			printf("\n*                          *");
			printf("\n*                          *");
			printf("\n****************************");
			exit(0); 
		} 
		else 
		{
			printf("\n\t\t*    ͨѶ¼�ļ��ѽ���!     *"); 
			printf("\n\t\t*                          *");
			printf("\n\t\t*                          *");
			printf("\n\t\t****************************");
			printf("\n\t\t      ��������������˵�    "); 
			printf("\n\t\t          ��������������ѡ��:    ");
		    scanf("%d",&k);
			return;		
		} 
		exit(0); 
	} 
	fseek(fp,0,2); //*�ļ�λ��ָ���ƶ����ļ�ĩβ*// 
	if (ftell(fp)>0) //*�ļ���Ϊ��*// 
	{ 
		rewind(fp); //*�ļ�λ��ָ���ƶ����ļ���ʼλ��*// 
		for (num=0;!feof(fp) && fread(&per[num],sizeof(struct person),1,fp);num++); 
		printf("\n\t\t****************************");
		printf("\n\t\t*                          *");
		printf("\n\t\t*                          *");
		printf("\n\t\t*     �ļ�����ɹ�!        *");  
		printf("\n\t\t*                          *");
		printf("\n\t\t*                          *");
		printf("\n\t\t****************************");
		printf("\n\t\t     ��1��ʾ������Ϣ����2�����˵���     "); 
		printf("\t\t          ��������������ѡ��:    ");
		scanf("%d",&j); 
		if(j==1)
		  showall(); 
	}
else
 {
	printf("\n\t\t****************************");
	printf("\n\t\t*                          *");
	printf("\n\t\t*                          *");
	printf("\n\t\t*     �ļ�����ɹ�!        *"); 
	printf("\n\t\t*  ͨѶ¼�ļ������κμ�¼! *"); 
	printf("\n\t\t*                          *");
	printf("\n\t\t*                          *");
	printf("\n\t\t****************************");
	printf("\n\t\t�밴�������ּ��������˵�"); 
	scanf("%d",&i); 
	return; 
}
} 



void deleteall()//*ɾ��������Ϣ*//
{ 
    int i,j;
	system("cls"); 
	system("color 50");
	printf("\n\t\tȷ��ɾ��?\n");
	printf("�밴1��2��1����ȷ�ϣ�2����ɾ����\n ");
	scanf("%d",&i);
	if (i==1) 
	{ 
		fclose(fp); 
		if ((fp=fopen("per.bin","wb"))==NULL) 
	     { 
		    printf("\n\t\t���ܴ��ļ���ɾ��ʧ��"); 
		    readfromfile(); 
	     } 
	    num=0; 
	    printf("\n\t\t��¼��ɾ��!"); 
	    printf("\n\t\t�밴�������ּ��������˵�"); 
	    scanf("%d",&j); 
	    return; 
	} 

} 
