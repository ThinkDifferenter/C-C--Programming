typedef struct student
{
	int no;
	char name[10];
	char sex[3];
	char age;
	char mobile[13];
	char QQ[13];
	char address[80];
	struct student *next;
}STU;
char password;
STU *student_first,*student_end;
char gsave,gfirst;

void addstu(void);
void findstu(void);
void liststu(void);
void modifystu(void);
void summarystu(void);
void delstu(void);
void resetpwd(void);
void readdate(void);
void savedate(void);
char *modi_file(char *file,char *s,int n);
STU *findname(char *name);
STU *findno(int no);
STU *findmobile(char *name);
STU *findQQ(char *name);
void displaystu(STU *stu,char *file,char *name);
void cheakfirst(void);
void bound(char ch,int n);
void login();
void menu();
 
