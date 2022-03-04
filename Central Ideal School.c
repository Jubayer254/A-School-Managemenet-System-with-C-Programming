#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

int loginFlag=0;
int stdCount=0;
int choice_login;
int AdminCount;

typedef struct
{
    char name[20];
    char id[20];
    int age;
    char date[20];
    char fName[20];
    char mName [20];
    int gender;
    char addrs[50];
    int Class;
    int payment;
} student;

typedef struct
{
    char name[50];
    char id[50];
    int age;
    char date[50];
    char fName[50];
    char mName [50];
    char gender[50];
    char addrs[100];
    int Class;
    int payment;
} students;

typedef struct
{
    char name[50];
    char pass[50];
    char ConPass[50];
} admin;

student s;
students std[100000];
admin a;
admin ad[1000];

void AddAdmin()
{
    printf("\n");
    printf("                     ********CREATE ADMIN ACCOUNT*******\n\n");
    printf("Enter Name:\n");
    fflush(stdin);
    gets(a.name);
    printf("\n");
    printf("Enter Password:\n");
    fflush(stdin);
    gets(a.pass);
    printf("\n");
    printf("Confirm Password:\n");
    fflush(stdin);
    gets(a.ConPass);
    printf("\n");

    if(strcmp(a.pass,a.ConPass)==0)
    {
        FILE *ADData;
        ADData = fopen("Admin.txt","a");
        if(ADData == NULL)
        {
            printf("FILE DOES NOT EXIST");
        }
        else
        {
            fputs(a.name,ADData);
            fprintf(ADData, "\n");
            fputs(a.pass,ADData);
            fprintf(ADData, "\n");
        }
        fclose(ADData);
        printf("\n\t\t\t Admin Added Successfully :)\n");
        login();
    }

    else
    {
        printf("\n\t\t\t Password Did Not Matched!!!!!\n");
        printf("\n\t\t\t    Re-create Account!!!!!\n");
        login();
    }
}

void error_fix()
{
    stdCount=0;
    FILE *show;
    show = fopen("stdData.txt","r");
    if(show == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        for(int i=0; !feof(show) ; i++, stdCount++)
        {
            fgets(std[i].name,50,show);
            fgets(std[i].id,50,show);
            fgets(std[i].date,50,show);
            fscanf(show,"%d\n",&std[i].age);
            fgets(std[i].fName,50,show);
            fgets(std[i].mName,50,show);
            fgets(std[i].gender,50,show);
            fgets(std[i].addrs,50,show);
            fscanf(show,"%d\n",&std[i].Class);
            fscanf(show,"%d\n",&std[i].payment);
        }
        fclose(show);
    }
}

void AddStd()
{
    printf("\n");
    printf("                     ********INSERT STUDENT DATA*******\n\n");
    printf("Enter Name:\n");
    fflush(stdin);
    gets(s.name);
    printf("\n");
    printf("Enter ID:\n");
    fflush(stdin);
    gets(s.id);
    printf("\n");
    printf("Enter Date of Birth (dd/mm/yyyy):\n");
    fflush(stdin);
    scanf("%s",&s.date);
    printf("\n");
    printf("Enter Age:\n");
    scanf("%d",&s.age);
    printf("\n");
    printf("Enter Father's Name:\n");
    fflush(stdin);
    gets(s.fName);
    printf("\n");
    printf("Enter Mother's Name:\n");
    fflush(stdin);
    gets(s.mName);
    printf("\n");
    printf("Enter Gender:\n");
    printf("1 - Male\n");
    printf("2 - Female\n");
    printf("3 - Other\n");
    scanf("%d",&s.gender);
    printf("\n");
    printf("Enter Address:\n");
    fflush(stdin);
    gets(s.addrs);
    printf("\n");
    printf("Enter Class:\n");
    scanf("%d",&s.Class);
    s.payment=0;

    printf("\n\n");
    printf("\t--------------------------------STUDENT INFORMATIONS--------------------------------\n");
    printf("\t====================================================================================\n");
    printf("\t Name: %s\n",s.name);
    printf("\t ID:   %s\n",s.id);
    printf("\n");
    printf("\t\t\t                              Date  of Birth    : %s\n",s.date);
    printf("\t\t\t                              Age               : %d\n",s.age);
    printf("\t\t\t                              Fathers Name      : %s\n",s.fName);
    printf("\t\t\t                              Mothers Name      : %s\n",s.mName);
    if(s.gender == 1)
        printf("\t\t\t                              Gender            : Male\n");
    if(s.gender == 2)
        printf("\t\t\t                              Gender            : Female\n");
    if(s.gender == 3)
        printf("\t\t\t                              Gender            : Other\n");
    printf("\t\t\t                              Address           : %s\n",s.addrs);
    printf("\t\t\t                              Class             : %d\n",s.Class);
    printf("\t\t\t                              Payment           : %d\n",s.payment);
    printf("\t===================================================================================\n");

    FILE *stdwrt;
    stdwrt = fopen("Students Information.txt","a");
    if(stdwrt == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        fprintf(stdwrt,"-------------------------------------------------------------------------\n");
        fprintf(stdwrt,"Name: ");
        fputs(s.name,stdwrt);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"ID: ");
        fputs(s.id,stdwrt);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Date of Birth: ");
        fputs(s.date,stdwrt);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Age: ");
        fprintf(stdwrt,"%d",s.age);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Father's Name: ");
        fputs(s.fName,stdwrt);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Mother's Name: ");
        fputs(s.mName,stdwrt);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Gender: ");
        if(s.gender == 1)
            fprintf(stdwrt,"MALE");
        if(s.gender == 2)
            fprintf(stdwrt,"FEMALE");
        if(s.gender == 3)
            fprintf(stdwrt,"OTHER");
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Address: ");
        fputs(s.addrs,stdwrt);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Class: ");
        fprintf(stdwrt,"%d",s.Class);
        fprintf(stdwrt, "\n");
        fprintf(stdwrt,"Total Payment: ");
        fprintf(stdwrt,"%d",s.payment);
        fprintf(stdwrt, "\n");
        fclose(stdwrt);
    }

    FILE *stdData;
    stdData = fopen("stdData.txt","a");
    if(stdData == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        fputs(s.name,stdData);
        fprintf(stdData, "\n");
        fputs(s.id,stdData);
        fprintf(stdData, "\n");
        fputs(s.date,stdData);
        fprintf(stdData, "\n");
        fprintf(stdData,"%d",s.age);
        fprintf(stdData, "\n");
        fputs(s.fName,stdData);
        fprintf(stdData, "\n");
        fputs(s.mName,stdData);
        fprintf(stdData, "\n");
        if(s.gender == 1)
            fprintf(stdData,"MALE");
        if(s.gender == 2)
            fprintf(stdData,"FEMALE");
        if(s.gender == 3)
            fprintf(stdData,"OTHER");
        fprintf(stdData, "\n");
        fputs(s.addrs,stdData);
        fprintf(stdData, "\n");
        fprintf(stdData,"%d",s.Class);
        fprintf(stdData, "\n");
        fprintf(stdData,"%d",s.payment);
        fprintf(stdData, "\n");
        fclose(stdData);
    }
    printf("\n\t\t\t Student Added Successfully :)\n");
    AdminAccess();
}

void AdminVarification(char InputAdName[], char InputAdPass[])
{
    AdminCount=0;
    FILE *Ad;
    Ad = fopen("Admin.txt","r");
    if(Ad == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        for(int i=0; !feof(Ad) ; i++, AdminCount++)
        {
            fgets(ad[i].name,50,Ad);
            fgets(ad[i].pass,50,Ad);
        }
        fclose(Ad);
    }
    strcat(InputAdName,"\n");
    strcat(InputAdPass,"\n");

    for(int i = 0; i<AdminCount ; i++)
    {
        if(strcmp(ad[i].name,InputAdName)==0 && strcmp(ad[i].pass,InputAdPass)==0)
        {
            loginFlag=1;
            break;
        }
    }
}

void update_payment()
{
    error_fix();
    int pay;
    char SRCname[50];
    char SRCid[50];
    int SRCclass;
    printf("\n\n");
    printf("Enter The Student Name:\n");
    fflush(stdin);
    gets(SRCname);
    printf("\n");
    printf("Enter The Student ID:\n");
    fflush(stdin);
    gets(SRCid);
    printf("\n");
    printf("Enter The Student Class:\n");
    scanf("%d",&SRCclass);
    printf("\n");
    printf("Enter The Amount of Payment:\n");
    scanf("%d",&pay);
    strcat(SRCname,"\n");
    strcat(SRCid,"\n");

    int flag=0;

    FILE *stdData2;
    stdData2 = fopen("stdData.txt","w");
    if(stdData2 == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        for(int i = 0; i<stdCount; i++)
        {
            fputs(std[i].name,stdData2);
            fputs(std[i].id,stdData2);
            fputs(std[i].date,stdData2);
            fprintf(stdData2,"%d",std[i].age);
            fprintf(stdData2, "\n");
            fputs(std[i].fName,stdData2);
            fputs(std[i].mName,stdData2);
            fputs(std[i].gender,stdData2);
            fputs(std[i].addrs,stdData2);
            fprintf(stdData2,"%d",std[i].Class);
            fprintf(stdData2, "\n");
            if(strcmp(std[i].name,SRCname)==0 && strcmp(std[i].id,SRCid)==0 && (std[i].Class == SRCclass))
            {
                flag=1;
                std[i].payment=std[i].payment+pay;
                fprintf(stdData2,"%d",std[i].payment);
                fprintf(stdData2, "\n");
            }
            else
            {
                fprintf(stdData2,"%d",std[i].payment);
                fprintf(stdData2, "\n");
            }
        }
        fclose(stdData2);
    }


    FILE *stdwrt2;
    stdwrt2 = fopen("Students Information.txt","w");
    if(stdwrt2 == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        for(int i = 0; i<stdCount; i++)
        {
            fprintf(stdwrt2,"-------------------------------------------------------------------------\n");
            fprintf(stdwrt2,"Name: ");
            fputs(std[i].name,stdwrt2);
            fprintf(stdwrt2,"ID: ");
            fputs(std[i].id,stdwrt2);
            fprintf(stdwrt2,"Date of Birth: ");
            fputs(std[i].date,stdwrt2);
            fprintf(stdwrt2,"Age: ");
            fprintf(stdwrt2,"%d",std[i].age);
            fprintf(stdwrt2, "\n");
            fprintf(stdwrt2,"Father's Name: ");
            fputs(std[i].fName,stdwrt2);
            fprintf(stdwrt2,"Mother's Name: ");
            fputs(std[i].mName,stdwrt2);
            fprintf(stdwrt2,"Gender: ");
            fputs(std[i].gender,stdwrt2);
            fprintf(stdwrt2,"Address: ");
            fputs(std[i].addrs,stdwrt2);;
            fprintf(stdwrt2,"Class: ");
            fprintf(stdwrt2,"%d",std[i].Class);
            fprintf(stdwrt2, "\n");
            fprintf(stdwrt2,"Total Payment: ");
            fprintf(stdwrt2,"%d",std[i].payment);
            fprintf(stdwrt2, "\n");
        }
        fclose(stdwrt2);
    }

    if(flag==0)
    {
        printf("\n\t\t\t Student Did Not Found!!!!!\n");
        AdminAccess();
    }
    else
    {
        printf("\n\t\t\t Payment Added Successfully :)\n");
        AdminAccess();
    }
}

void dlt_std()
{
    error_fix();
    char SRCname[50];
    char SRCid[50];
    int SRCclass;
    printf("\n\n");
    printf("Enter The Student Name:\n");
    fflush(stdin);
    gets(SRCname);
    printf("\n");
    printf("Enter The Student ID:\n");
    fflush(stdin);
    gets(SRCid);
    printf("\n");
    printf("Enter The Student Class:\n");
    scanf("%d",&SRCclass);
    printf("\n");
    strcat(SRCname,"\n");
    strcat(SRCid,"\n");

    int flag=0;

    FILE *stdData3;
    stdData3 = fopen("stdData.txt","w");
    if(stdData3 == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        for(int i = 0; i<stdCount; i++)
        {
            if(strcmp(std[i].name,SRCname)==0 && strcmp(std[i].id,SRCid)==0 && (std[i].Class == SRCclass))
            {
                flag=1;
            }
            else
            {

                fputs(std[i].name,stdData3);
                fputs(std[i].id,stdData3);
                fputs(std[i].date,stdData3);
                fprintf(stdData3,"%d",std[i].age);
                fprintf(stdData3, "\n");
                fputs(std[i].fName,stdData3);
                fputs(std[i].mName,stdData3);
                fputs(std[i].gender,stdData3);
                fputs(std[i].addrs,stdData3);
                fprintf(stdData3,"%d",std[i].Class);
                fprintf(stdData3, "\n");
                fprintf(stdData3,"%d",std[i].payment);
                fprintf(stdData3, "\n");

            }
        }
        fclose(stdData3);
    }


    FILE *stdwrt3;
    stdwrt3 = fopen("Students Information.txt","w");
    if(stdwrt3 == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        for(int i = 0; i<stdCount; i++)
        {
            if(strcmp(std[i].name,SRCname)==0 && strcmp(std[i].id,SRCid)==0 && (std[i].Class == SRCclass))
            {
                flag=1;
            }
            else
            {
                fprintf(stdwrt3,"-------------------------------------------------------------------------\n");
                fprintf(stdwrt3,"Name: ");
                fputs(std[i].name,stdwrt3);
                fprintf(stdwrt3,"ID: ");
                fputs(std[i].id,stdwrt3);
                fprintf(stdwrt3,"Date of Birth: ");
                fputs(std[i].date,stdwrt3);
                fprintf(stdwrt3,"Age: ");
                fprintf(stdwrt3,"%d",std[i].age);
                fprintf(stdwrt3, "\n");
                fprintf(stdwrt3,"Father's Name: ");
                fputs(std[i].fName,stdwrt3);
                fprintf(stdwrt3,"Mother's Name: ");
                fputs(std[i].mName,stdwrt3);
                fprintf(stdwrt3,"Gender: ");
                fputs(std[i].gender,stdwrt3);
                fprintf(stdwrt3,"Address: ");
                fputs(std[i].addrs,stdwrt3);;
                fprintf(stdwrt3,"Class: ");
                fprintf(stdwrt3,"%d",std[i].Class);
                fprintf(stdwrt3, "\n");
                fprintf(stdwrt3,"Total Payment: ");
                fprintf(stdwrt3,"%d",std[i].payment);
                fprintf(stdwrt3, "\n");
            }
        }
        fclose(stdwrt3);
    }

    if(flag==0)
    {
        printf("\n\t\t\t Student Did Not Found!!!!!\n");
        AdminAccess();
    }
    else
    {
        printf("\n\t\t\t Student Deleted Successfully :)\n");
        AdminAccess();
    }
}

void seeinfostd()
{
    stdCount=0;
    char SRCname[50];
    char SRCid[50];
    int SRCclass;
    printf("\n\n");
    printf("Enter The Student Name:\n");
    fflush(stdin);
    gets(SRCname);
    printf("\n");
    printf("Enter The Student ID:\n");
    fflush(stdin);
    gets(SRCid);
    printf("\n");
    printf("Enter The Student Class:\n");
    scanf("%d",&SRCclass);
    strcat(SRCname,"\n");
    strcat(SRCid,"\n");

    FILE *show;
    show = fopen("stdData.txt","r");
    if(show == NULL)
    {
        printf("FILE DOES NOT EXIST");
    }
    else
    {
        printf("\n");
        //read
        for(int i=0; !feof(show) ; i++, stdCount++)
        {
            fgets(std[i].name,50,show);
            fgets(std[i].id,50,show);
            fgets(std[i].date,50,show);
            fscanf(show,"%d\n",&std[i].age);
            fgets(std[i].fName,50,show);
            fgets(std[i].mName,50,show);
            fgets(std[i].gender,50,show);
            fgets(std[i].addrs,50,show);
            fscanf(show,"%d\n",&std[i].Class);
            fscanf(show,"%d\n",&std[i].payment);
        }
        fclose(show);
    }


    int Flag=0;
    for(int i=0; i<stdCount; i++)
    {
        if(strcmp(std[i].name,SRCname)==0 && strcmp(std[i].id,SRCid)==0 && (std[i].Class == SRCclass))
        {
            Flag=1;
            printf("\t--------------------------------STUDENT INFORMATIONS--------------------------------\n");
            printf("\t====================================================================================\n");
            printf("\tName         : %s",std[i].name);
            printf("\tID           : %s",std[i].id);
            printf("\tDate of Birth: %s",std[i].date);
            printf("\tAge          : %d\n",std[i].age);
            printf("\tFather's Name: %s",std[i].fName);
            printf("\tMother's Name: %s",std[i].mName);
            printf("\tGender       : %s",std[i].gender);
            printf("\tAddress      : %s",std[i].addrs);
            printf("\tClass        : %d\n",std[i].Class);
            printf("\tPayment      : %d\n\n",std[i].payment);
            printf("\t====================================================================================\n");
        }
    }
    if(Flag==0)
    {
        printf("\t\t\t Student Did Not Found!!!\n");
    }
    AdminAccess();
}

char* substr(const char *str, int m, int n)
{
    int len = n - m;
    char *temp = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = m; i < n && (*(str + i) != '\0'); i++)
    {
        *temp = *(str + i);
        temp++;
    }
    *temp = '\0';
    return temp - len;
}

void seebd()
{
    error_fix();
    char SRCdate[50];
    printf("\n\n");
    printf("Enter Todays Date (dd/mm/yy):\n");
    fflush(stdin);
    gets(SRCdate);
    printf("\n");
    int Flag=0;
    for(int i=0; i<stdCount; i++)
    {
        if(strcmp(substr(std[i].date,0,6),substr(SRCdate,0,6))==0)
        {
            Flag=1;
            printf("\t-----------------------------------BIRTHDAY-----------------------------------------\n");
            printf("\t====================================================================================\n");
            printf("\tName         : %s",std[i].name);
            printf("\tID           : %s",std[i].id);
            printf("\tClass        : %d\n",std[i].Class);
            printf("\t====================================================================================\n");
        }
    }
    if(Flag==0)
    {
        printf("\t\t\t No Students Have Birthday Today!!!\n");
    }
    AdminAccess();
}


void AdminAccess()
{
    char* dis[100];
    loginFlag = 0;
    dis[0]= ("\n");
    dis[1]= "                     ********WELCOME ADMIN********\n";
    dis[2]= "\n";
    dis[3]= "====================================================================\n";
    dis[4]= "||             1- Register New Student                             ||\n";
    dis[5]= "||             2- See Student Information                          ||\n";
    dis[6]= "||             3- Delete Student                                   ||\n";
    dis[7]= "||             4- Update Payment                                   ||\n";
    dis[8]= "||             5- See Which Students Have Birthday Today           ||\n";
    dis[9]= "||             6- Logout                                           ||\n";
    dis[10]="||             7- Exit System                                      ||\n";
    dis[11]="====================================================================\n";

    for(int i=0; i<=11; i++)
    {
        printf("%s",dis[i]);
        Sleep(150);
    }
    int choice;
    printf("\n");
    printf("  Enter your choice: ");
    scanf("%d",&choice);

    //registration of students
    if(choice==1)
    {
        AddStd();
    }
    else if(choice==2)
    {
        seeinfostd();
    }
    else if(choice==3)
    {
        dlt_std();
    }
    else if(choice==4)
    {
        update_payment();
    }
    else if(choice==5)
    {
        seebd();
    }
    else if(choice==6)
    {
        login();
    }
    else if(choice==7)
    {
        printf("\t\t\t The Program Has Been Shut Down :) \n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t Please Enter A Valid Input!!!!!\n");
        AdminAccess();
    }

}

void select_1()
{

    char InputAdName[50];
    char InputAdPass[50];

    printf("\n");
    printf("Enter Your Admin Username:\n");
    scanf("%s",&InputAdName);
    printf("Enter Your Admin Password:\n");
    scanf("%s",&InputAdPass);

    AdminVarification(InputAdName, InputAdPass);

    int j = -1;
    for(j = 3; j>=1 ; j--)
    {
        if(loginFlag != 1)
        {
            printf("\n");
            printf("\t\t                Wrong Password!!!!!\n");
            printf("\t\t                 Please Try Again!\n");
            printf("\t\t You Have %d Chance After That The Program Will Terminate!\n",j);
            printf("\n");

            printf("\n");
            printf("Enter Your Admin Username:\n");
            scanf("%s",&InputAdName);
            printf("Enter Your Admin Password:\n");
            scanf("%s",&InputAdPass);
            printf("\n");
            AdminVarification(InputAdName, InputAdPass);
        }
        if(loginFlag == 1)
        {
            AdminAccess();
            break;
        }
    }
    if(j == 0)
    {
        printf("\t\t\t Program Has Been Terminated!!!\n");
        exit(0);
    }

}

void login()
{

    printf("\n");
    printf("\n");
    printf("\n");

    char* dis[100];
    dis[1] ="                        CENTRAL IDEAL SCHOOL\n";
    dis[2] ="\n";
    dis[3] ="                    ********LOGIN SCREEN*********\n";
    dis[4] ="\n";
    dis[5] ="====================================================================\n";
    dis[6] ="||             1- To Administrator Login                          ||\n";
    dis[7] ="||             2- To Create Administrator Account                 ||\n";
    dis[8] ="||             3- Exit System                                     ||\n";
    dis[9] ="====================================================================\n";

    for(int i=1; i<=9; i++)
    {
        printf("%s",dis[i]);
        Sleep(150);
    }
    printf("\n");
    printf("  Enter your choice: ");
    scanf("%d",&choice_login);
}


int main()
{
    login();
    while(1)
    {

        if(choice_login == 1)
        {
            select_1();
        }

        else if(choice_login == 2)
        {
            AddAdmin();
        }
        else if(choice_login == 3)
        {
            printf("\n");
            printf("\t\t\t The Program Has Been Shut Down :) \n");
            printf("\n");
            exit(0);
        }
        else
        {
            printf("\n\t\t\t Please Enter A Valid Input!!!!!\n");
            login();
        }
    }
    return 0;
}



