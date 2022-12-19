#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void menu();
void add();
void view();
void search();
void modify();
void eraserec();
void exit1(void);

struct student
{
	char name[30];
	char gender[10];
	int mobile,rollno;
	char address[30];
	char email[35];
	char streme[20];
	
};
int main()
{
	 printf("\n\n\n\t\tSTUDENT RECORD MANAGEMENT SYSTEM \n");
	 printf("\t\t---------------------------------------------------------\n\n");
	 printf("\t\t Press any key to continue");
	 getch();
	 menu();
	 return 0;
}

void menu()
{
	char choice;
	system("cls");
	printf("\n\n\t\t\t-------MAIN MENU--------\n\n");
	printf("\t\ta) Add record\n");
	printf("\t\tb)View record\n");
	printf("\t\tc)Search record\n");
	printf("\t\td)Modify record\n");
	printf("\t\te)Erase\n");
	printf("\t\tf)Exit\n");
	printf("\n\n\t\tChoose from a to f\n\t\t");
	scanf("%c",&choice);
	switch(choice)
	{
		case 'a':
			add();
			break;
			case 'b':
				view();
				break;
				case 'c':
					search();
					break;
					case 'd':
						modify();
						break;
						case 'e':
							eraserec();
							break;
							case 'f':
								exit1();
								break;
								default:
									printf("\t\tInvalid choice");
									
	}
}

void add()
{
	FILE *fp;
	struct student std;
	char another = 'y';
	system("cls");
	fp=fopen("filere.txt","ab+");
	if(fp==NULL){
		printf("\n\n\tError opening file");
		exit(1);
		
	}
	fflush(stdin);
	while(another=='y')
	{
		printf("ADD RECORD\n\n");
		printf("Enter details of student\n");
		printf("Enter name:   ");
		gets(std.name);
		printf("Gender:   ");
		gets(std.gender);
		printf("Address:");
		gets(std.address);
		printf("Mobile number:");
		scanf("%d",&std.mobile);
		fflush(stdin);
		printf("Rollno:");
		scanf("%d",&std.rollno);
		fflush(stdin);
		printf("Email:");
		gets(std.email);
		printf("Streme");
		gets(std.streme);
		fwrite(&std,sizeof(std),1,fp);
		printf("Press'y'to add another data otherwise'any key'.");
		fflush(stdin);
		another=getch();
		system("cls");
		fflush(stdin);
	}
	fclose(fp);
	printf("Press any key to continue");
	getch();
	menu();
}

void view()
{
	FILE *fp;
	int i=1;
	struct student std;
	system("cls");
	printf("\t\t----VIEW RECORD---\n\n");
	printf("s.no.   Name of student\t\t Mobile no.\t\t rollno\t\t address\t\t email\t\t streme\n");
	printf("---------------------------------------------------------\n");
	fp=fopen("filere.txt","rb+");
	if(fp==NULL){
		printf("\n\nerror opening file");
		exit(1);
	}
	while(fread(&std,sizeof(std),1,fp)==1){
		fflush(stdin);
		printf("%d>%s\t\t%d\t\t%s\t\t%s\n",i,std.name,std.mobile,std.rollno,std.address,std.email,std.streme);
		i++;
	}
	fclose(fp);
	printf("\n\n Press any key to continue");
	getch();
	menu();
}

void search()
{
	FILE *fp;
	struct student std;
	char stname[20];
	system("cls");
	printf("\n\n\t\t\t-----SEARCH RECORD------\n\n");
	printf("\tEnter name of student");
	fflush(stdin);
	gets(stname);
	fp=fopen("filere.txt","rb+");
	if(fp==NULL){
		printf("\n\n\t\t Error opening file");
		exit(1);
	}
	while(fread(&std,sizeof(std),1,fp)==1){
		if(strcmp(stname,std.name)==0){
			printf("\n\n\t Name   :%s\n",std.name);
				printf("\n\n\t Gender   :%s\n",std.gender);
					printf("\n\n\t Mobileno   :%d\n",std.mobile);
				printf("\n\n\t rollno   :%d\n",std.rollno);
				printf("\n\n\t address   :%s\n",std.address);
				printf("\n\n\t Email   :%s\n",std.email);
				printf("\n\n\t streme   :%s\n",std.streme);
			
		}
	}
	fclose(fp);
	printf("\n\n\t\tPress any key to continue");
	getch();
	menu();
}

void modify()
{
	char stname[20];
	FILE *fp;
	struct student std;
	system("cls");
	printf("\n\t\t-----MODIFY RECORD-----");
	printf("/n\tEnter name of student to modify:");
	fflush(stdin);
	gets(stname);
	fp=fopen("filere.txt","rb+");
	if(fp==NULL){
		printf("\n\n\t\tErroer opening file");
		exit(1);
	}
	rewind(fp);
	fflush(stdin);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(strcmp(stname,std.name)==0)
		{
			printf("\nEnter name:");
			gets(std.name);
			printf("Gender:");
			gets(std.gender);
			printf("address:");
			gets(std.address);
			printf("Enter mobile no:");
			scanf("%d",&std.mobile);
			printf("Enter rollno:");
			scanf("%d",&std.rollno);
			fflush(stdin);
			printf("Email:");
			gets(std.email);
			printf("Streme:");
			gets(std.streme);
			fseek(fp,sizeof(std),SEEK_CUR);
			fwrite(&std,sizeof(std),1,fp);
			break;
		}
	}
	fclose(fp);
	printf("\n\n\t\t Press any key to continue");
	getch();
	menu();
}

void eraserec()
{
	char stname[20];
	FILE *fp,*ft;
	struct student std;
	system("cls");
	printf("\n\t\t------ERASE RECORD------");
	printf("\n\nEnter name of student to erase record:");
	fflush(stdin);
	gets(stname);
	fp=fopen("filere.txt","rb+");
	if(fp==NULL){
		printf("\n\n\t\t Error opening file");
		exit(1);
	}
	while(fread(&std,sizeof(std),1,fp)==1){
		if(strcmp(stname,std.name)!=0)
		fwrite(&std,sizeof(std),1,ft);
	}
	fclose(fp);
	fclose(ft);
	remove("filere.txt");
	rename("file2.txt","file.txt");
	printf("\n\n\t\t Press any key to continue");
	getch();
	menu();
}

void exit1(void)
{
	system("cls");
	printf("\n\n\n\n\t\t\t  THANKS FOR VISITING");
	printf("\n\n\n\n\t\t\t project on student record management\n");
	getch();
}
