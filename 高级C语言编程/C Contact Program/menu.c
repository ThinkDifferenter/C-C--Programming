void menu(void)
{
	char chioce;
	
	system("cls");
	
	do
	{
		printf("\tѧ������ϵͳ\n");
		bound('_',30);
		printf("\n��ѡ��˵�:");
		printf("\t1.����ѧ����Ϣ:\n");
		printf("\t2.��ѯѧ����Ϣ:\n");
		printf("\t3.�޸�ѧ����Ϣ:\n");
		printf("\t4.ɾ��ѧ����Ϣ:\n");
		printf("\t5.ͳ��ѧ����Ϣ:\n");
		printf("\t6.����ϵͳ����:\n");
		printf("\t0.�Ƴ�ϵͳ\n");
		bound('_',30);
		
		do
		{
			fflush(stdin);
			chioce=getchar(); 
			system("cls");
			
			swith(choice)
			{
				case '1':  addstu();  break;
				case '2': 
				{
					if(gfirst)
					{
						printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
						break;
					}
					else
					{
						findstu();
						break;
					}
					
				}
				case '3':
				if(gfirst)
				{
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
					break;
				}
				else
				{
					liststu();
					break;
				}
				case '4':
				if(gfirst)
				{
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
					break;
				}
				else
				{
					modifystu();
					break;
				}
				case '5':
				if(gfirst)
				{
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
					break;
				}
				else
				{
					delstu();
					break;
				}
				case '6':
				if(gfirst)
				{
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
					break;
				}
				else
				{
					summarystu();
					break;
				}
				case '7': resetpwd();   break;
				case '0': savedate();	exit(0);
				
			}
		}while(choice<'0'||choice>'7');
		system("cls");
	}while(1);	
} 
