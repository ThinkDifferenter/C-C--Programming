void menu(void)
{
	char chioce;
	
	system("cls");
	
	do
	{
		printf("\t学生管理系统\n");
		bound('_',30);
		printf("\n请选择菜单:");
		printf("\t1.输入学生信息:\n");
		printf("\t2.查询学生信息:\n");
		printf("\t3.修改学生信息:\n");
		printf("\t4.删除学生信息:\n");
		printf("\t5.统计学生信息:\n");
		printf("\t6.重设系统密码:\n");
		printf("\t0.推出系统\n");
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
						printf("系统中还没有同学信息，请添加同学信息!");
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
					printf("系统中还没有同学信息，请添加同学信息!");
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
					printf("系统中还没有同学信息，请添加同学信息!");
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
					printf("系统中还没有同学信息，请添加同学信息!");
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
					printf("系统中还没有同学信息，请添加同学信息!");
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
