#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

char id[20],ids[20],idso[20],c;
char pass[20];
int i,j,p,l1=0,l2=0,l3=0,l4=0;

void get_detail();
void register_detail();

int main()

{
    int option=1;

    reset:
    printf("### Choose the option ###\n\n  1. Login\n  2. Register");
    printf("\n");
    printf(" \nEnter the option here: ");
    scanf("%d",&option);

    if(option==1)
    {
        system("cls");
        printf("\n\nEnter your username:");
        scanf("%s",id);

        get_detail();

        system("cls");

        printf("Select the option to proceed->\n");
        printf("   1.Main menu\n   2.Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&p);
        if(p==1)
        {
            system("cls");
            goto reset;
        }
        else if(p==2)
        {
            //system("exit");
            system("taskkill/IM cb_console_runner.exe");
        }
        else
        {
           printf("\nplease enter valid choice");
        }
    }
    else if(option==2)
    {
        system("cls");
        printf("\n\nEnter your username:");
        scanf("%s",id);

        register_detail();

        system("cls");

        printf("Select the option to proceed->\n");
        printf("   1.Main menu\n   2.Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&p);
        if(p==1)
        {
            system("cls");
            goto reset;
        }
        else if(p==2)
        {
           //system("exit");
            system("taskkill/IM cb_console_runner.exe");
        }
        else
        {
           printf("please enter valid choice");
        }

    }
    else
    {
        printf("You select wrong option...");
        printf("Press any key to select option again.");
        system("cls");
        goto reset;
    }




   return 0;
}
void get_detail()
{

    FILE *fr;
    fr=fopen("G:\\STUDY\\c project\\password.txt","r");

    for(i=0;fscanf(fr,"%s",idso)!=EOF;i++)
    {
        int c;
        c=strcmp(id,idso);
        //printf("%d\n",c);
        if(!c)
            {
             fscanf(fr,"%s",idso);
             break;
            }

    }

    fclose(fr);
    system("cls");
    printf("\nYou are registered Mr.%s",id);
    printf("\nYour password is '%s'",idso);
    getch();
    printf("\n");
    printf("\n");
    printf("\n");
}

void register_detail()
{
    FILE *fa;
    fa=fopen("G:\\STUDY\\c project\\password.txt","a");

    printf("\n");

    printf("Enter the Password:");
    for(i=0;i<20;i++)
    {
        c=getch();
        if(c==13)
        {
            pass[i]='\0';
            break;
        }
        else if(c==8)
        {
           printf("\b");
           i=i-2;

        }
        else
        {
            pass[i]=c;
            printf("*");
        }
    }
    printf("\n");

    for(i=0;i<20;i++)
    {
         if(pass[i]>='a'&&pass[i]<='z')
         {
             l1=1;
         }
         if(pass[i]>='A'&&pass[i]<='Z')
         {
             l3=1;
         }
         if(pass[i]>='0'&&pass[i]<='9')
         {
             l4=1;
         }
         if(pass[i]=='!'||pass[i]=='@'||pass[i]=='#'||pass[i]=='$'||pass[i]=='%'||pass[i]=='^'||pass[i]=='&'||pass[i]=='*'||pass[i]=='~')
         {
             l2=1;
         }
    }

    printf("\n");
    if(l1&&l2&&l3&&l4)
    {
        system("cls");

        printf("\n\n\n");
        printf("\a>>>>>> Welcome %s <<<<<<<",id);
        printf("\n\n\n");
        getch();
        fprintf(fa,"%s\n ",id);
        fprintf(fa,"%s\n",pass);
    }
    else
    {
        printf("please enter valid password");

    }

    fclose(fa);
}
