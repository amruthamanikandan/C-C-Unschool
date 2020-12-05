#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct diary
{
    char date[20];
    char time[20];
    char name[50];
    char place[100];
    char duration[10];
    char note[100];
};
struct diary ps[50];

char pass[50];
char npwd[50]="welcome";

void passwdprotect();
void add();
void view();
void update();
void del();
void updatepass();

int count=0;


int main()
{
   int choice=0;
   int i=0;
   char x;



   printf("\t \t \t \t*************************************");
   printf("\n \t \t \t \t* PASSWORD PROTECTED PERSONAL DIARY *");
   printf("\n \t \t \t \t*************************************");


   menu:
   printf("\n \n \t \t \t \t \t  MAIN MENU:");
   printf("\n \n \t \t \t \t ADD RECORD        [1]");
   printf("\n \t \t \t \t VIEW RECORD       [2]");
   printf("\n \t \t \t \t EDIT RECORD       [3]");
   printf("\n \t \t \t \t DELETE RECORD     [4]");
   printf("\n \t \t \t \t EDIT PASSWORD     [5]");
   printf("\n \t \t \t \t EXIT              [6]");
   printf("\n \n \t \t \t \t ENTER YOUR CHOICE:");
   scanf("%d",&choice);

   switch(choice)
   {
       case 1:add();
              goto menu;break;

       case 2: printf("\n \t \t ENTER PASSWORD TO ACCESS VIEW RECORDS OPTION:");
               passwdprotect();
               view();
               goto menu;break;

       case 3:printf("\n \t \t ENTER PASSWORD TO ACCESS EDIT RECORDS OPTION:");
              passwdprotect();
              update();
              goto menu;break;

       case 4:printf("\n \t \t ENTER PASSWORD TO ACCESS DELETE RECORDS OPTION:");
              passwdprotect();
              del();
              goto menu;break;

       case 5:updatepass();
              goto menu;break;

       case 6:printf("\n \t \t ENTER ANY KEY:");
              scanf("%c",x);break;

   }

    return 0;
}


void passwdprotect()
{
  verify:
  printf("\n \t \t ENTER PASSWORD:");
  scanf("%s",pass);
  if(strcmp(pass,npwd)==0)
        printf("\n \t \t PASSWORD VERIFIED!");
  else
  {
     printf("\n \t \t WRONG PASSWORD");
     goto verify;
  }

}



void add()
{
    char agree[10];
    int i=0;

     printf("\n \n \n");
     printf("\t \t \t \t*************************************");
     printf("\n \t \t \t \t    * WELCOME TO THE ADD MENU *");
     printf("\n \t \t \t \t*************************************");


     record:

     printf("\n \n \t \t ENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");
     scanf("%s",ps[i].date);
     printf("\n \n \t \t ENTER TIME:[hh:mm]:");
     scanf("%s",ps[i].time);
     printf(" \t \t ENTER NAME:");
     scanf("%s",ps[i].name);
     printf(" \t \t ENTER PLACE:");
     scanf("%s",ps[i].place);
     printf(" \t \t ENTER DURATION:");
     scanf("%s",ps[i].duration);
     printf(" \t \t ENTER NOTE:");
     scanf("%s",ps[i].note);
     printf("\n YOUR RECORD IS ADDED....");
     printf("\n \t \t ADD ANOTHER RECORD?....<Y/N>: ");
     scanf("%s",agree);
     count++;

     if(strcmp(agree,"y")==0)
     {
         i++;

        goto record;

     }
}



void view()
{
    int ch=0,i=0;
    char d[20];
    char agree[3];
    char t[30];

     printf("\n \n \n");
     printf("\t \t \t \t*************************************");
     printf("\n \t \t \t \t    * WELCOME TO THE VIEW MENU *");
     printf("\n \t \t \t \t*************************************");


     choice:
     printf("\n \n \t \t HOW WOULD YOU LIKE TO VIEW:");
     printf("\n \t \t 1.WHOLE RECORD OF THE DAY");
     printf("\n \t \t 2.RECORD OF FIXED TIME");
     printf("\n \n \t \t ENTER YOUR CHOICE:");
     scanf("%d",&ch);

    switch(ch)
    {
        case 1:printf("\n ENTER THE DATE OF RECORD TO BE DISPLAYED:");
               scanf("%s",d);
               for(i=0;i<count;i++)
               {
                   if(strcmp(d,ps[i].date)==0)
                   {
                       printf("\n THE WHOLE RECORD FOR %s IS:",ps[i].date);
                       printf("\n \n TIME: %s",ps[i].time);
                       printf("\n MEETING WITH: %s",ps[i].name);
                       printf("\n MEETING PLACE: %s",ps[i].place);
                       printf("\n DURATION: %s",ps[i].duration);
                       printf("\n NOTE: %s",ps[i].note);

                   }

            }break;

         case 2:printf("\n \n ENTER DATE OF RECORD TO BE DISPLAYED:");
                scanf("%s",d);
                printf("\n \n ENTER TIME OF THE RECORD:");
                scanf("%s",t);
                for(i=0;i<count;i++)
                {
                    if(strcmp(d,ps[i].date)==0)
                    {
                        if(strcmp(t,ps[i].time)==0)
                        {
                            printf("\n \n TIME: %s",ps[i].time);
                            printf("\n MEETING WITH: %s",ps[i].name);
                            printf("\n MEETING PLACE: %s",ps[i].place);
                            printf("\n DURATION: %s",ps[i].duration);
                            printf("\n NOTE: %s",ps[i].note);
                        }
                    }

                }break;


    }

    printf("\n WOULD YOU LIKE TO CONTINUE VIEWING? <Y/N>:");
    scanf("%s",agree);
    if(strcmp(agree,"y")==0)
    {
       goto choice;
    }


}



void update()
{
    char d[30];
    char t[30];
    int i=0;

    char ti[20];
    char n[50];
    char pl[100];
    char du[10];
    char no[100];


     printf("\n \n \n");
     printf("\t \t \t \t*************************************");
     printf("\n \t \t \t \t* WELCOME TO THE EDIT RECORDS MENU *");
     printf("\n \t \t \t \t*************************************");

     printf("\n \t \t ENTER DATE OF RECORD TO BE UPDATED:");
     scanf("%s",d);
     printf("\n \t \t ENTER THE TIME OF RECORD TO BE UPDATED:");
     scanf("%s",t);

      for(i=0;i<count;i++)
                {
                    if(strcmp(d,ps[i].date)==0)
                    {
                        if(strcmp(t,ps[i].time)==0)
                        {
                            printf("\n \n TIME: %s",ps[i].time);
                            printf("\n MEETING WITH: %s",ps[i].name);
                            printf("\n MEETING PLACE: %s",ps[i].place);
                            printf("\n DURATION: %s",ps[i].duration);
                            printf("\n NOTE: %s",ps[i].note);
                        }
                    }

                }


      printf("\n \n SPECIFY THE EDITS:");

      printf("\n \n \t \t ENTER TIME:[hh:mm]:");
      scanf("%s",ti);
      printf(" \t \t ENTER NAME:");
      scanf("%s",n);
      printf(" \t \t ENTER PLACE:");
      scanf("%s",pl);
      printf(" \t \t ENTER DURATION:");
      scanf("%s",du);
      printf(" \t \t ENTER NOTE:");
      scanf("%s",no);

      for(i=0;i<count;i++)
                {
                    if(strcmp(d,ps[i].date)==0)
                    {
                        if(strcmp(t,ps[i].time)==0)
                        {
                            printf("\n EDITED RECORD:");
                            printf("\n \n TIME: %s",strcpy(ps[i].time,ti));
                            printf("\n MEETING WITH: %s",strcpy(ps[i].name,n));
                            printf("\n MEETING PLACE: %s",strcpy(ps[i].place,pl));
                            printf("\n DURATION: %s",strcpy(ps[i].duration,du));
                            printf("\n NOTE: %s",strcpy(ps[i].note,no));
                        }
                    }

                }



}


void del()
{
    char d[30];
    char t[30];
    int i=0;


     printf("\n \n \n");
     printf("\t \t \t \t*************************************");
     printf("\n \t \t \t \t* WELCOME TO THE DELETE RECORDS MENU *");
     printf("\n \t \t \t \t*************************************");

     printf("\n \n ENTER THE DATE OF RECORD TO BE DELETED:");
     scanf("%s",d);
     printf("\n ENTER THE TIME OF RECORD TO BE DELETED:");
     scanf("%s",t);

      for(i=0;i<count;i++)
                {
                    if(strcmp(d,ps[i].date)==0)
                    {
                        if(strcmp(t,ps[i].time)==0)
                        {
                            ps[i]=ps[i+1];
                            printf("\n RECORD HAS BEEN DELETED!");
                        }
                    }


               }

}


void updatepass()
{
   char pwd[50];

   printf("\n \n \n");
   printf("\t \t \t \t*************************************");
   printf("\n \t \t \t \t* WELCOME TO THE EDIT PASSWORD MENU *");
   printf("\n \t \t \t \t*************************************");


    printf("\n \n :: FOR SECURITY PURPOSES :::: ONLY THREE TRIALS ARE ALLOWED ::");
    access:
    printf("\n \t \t ENTER CURRENT PASSWORD:");
    scanf("%s",pwd);
    if(strcmp(pwd,npwd)==0)
        printf("\n \t \t ACCESS GRANTED...");
    else
    {
          printf("\n \t \t ACCESS DENIED...");
          goto access;

    }


    printf("\n \t \t ENTER NEW PASSWORD:");
    scanf("%s",npwd);
    printf("\n \t \t PASSWORD CHANGED!!");


}










