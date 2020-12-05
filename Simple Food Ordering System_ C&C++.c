#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;
int s=0;
int pending=0;

struct customers
{
   char name[300];
};
struct customers n[50];

int serve(void);
int billamt(int item_nos,int qty);



int main()
{
   int i=0,serial,item_nos,qty;


   printf("\t \t \t \t \t Welcome to Cafe Aroma");
           for(i=1;i<=100;i++)
    {
        printf("\n");
        printf("\n 1.Order");
        printf("\n 2.Serve");
        printf("\n 3.Display");
        printf("\n 4.Exit the program");
        printf("\n Enter serial number: ");
        scanf("%d",&serial);
        switch(serial)
        {
            case 1:++count;
                   billamt(item_nos,qty);
                   break;
            case 2:serve();break;
            case 3:printf("\n Total orders taken: %d",count);
                   if(count==1)
                   {
                     printf("\n Total no. of orders served: 1");
                   }
                   else
                     printf("\n Total no. of orders served: %d",s);
                   printf("\n No. of orders currently waiting to be served: %d",pending);
                   if(count==1)
                     {
                       printf("\n Currently no food being prepared");
                     }
                   else
                       printf("\n Currently food being prepared for order no. :%d",count);
                   break;
            case 4:printf("\n Enter any key: ");
                   scanf("%c",'y');break;
            default:printf("invalid serial entered");break;

        }

    }





    return 0;
}


int billamt(int item_nos,int qty)
{
   float amount=0;
   int price=0,i=0;
   char quest[10];
   float sie=0;
   int code=0;
   printf("Please enter your name: ");
   for(int i=count-1;i<count;i++)
   {
     scanf("%s",n[i].name);
   }

   printf("\n ----------------------------------------------MENU-----------------------------------------------");
   printf("\n Item Code   Description--------------------------Size---------------------------Price(tk)");
   printf("\n [11]--------Burger-------------------------------200/100gm---------------------130/100");
   printf("\n [12]--------Chicken Pizza--------------------------12/14/16inch------------------750/975/1250");
   printf("\n [13]--------Fried Chicken------------------------1/4/10pcs---------------------85/320/790");
   printf("\n [14]--------Grilled Chicken----------------------quarter/half/full-------------70/140/250");
   printf("\n [15]--------Noodles------------------------------half/full---------------------130/250");
   printf("\n [16]--------Pasta--------------------------------half/full---------------------120/240");
   printf("\n [17]--------Oreo Shake---------------------------250mg-------------------------180");
   printf("\n [18]--------Cold Coffee--------------------------250mg-------------------------65");
   printf("\n [19]--------Cappuccino---------------------------250mg-------------------------70");
   printf("\n [20]--------Coke---------------------------------250/500mg---------------------20/30");

   printf("\n How many items do you want to order? :");
   scanf("%d",&item_nos);
   IT:printf("Enter chosen item code: ");
    scanf("%d",&code);
    switch(code)
      {
          case 11:printf("Burger");break;
          case 12:printf("Chicken Pizza");break;
          case 13:printf("Fried Chicken");break;
          case 14:printf("Grilled Chicken");break;
          case 15:printf("Noodles");break;
          case 16:printf("Pasta");break;
          case 17:printf("Oreo Shake");break;
          case 18:printf("Cold Coffee");break;
          case 19:printf("Cappuccino");break;
          case 20:printf("Coke");break;

      }
      printf("\n Enter size: ");
      scanf("%f",&sie);

      switch(code)
      {
          case 11: if(sie==200)
                     price=130;
                   else
                     price=100;break;
          case 12: if(sie==12)
                    price=750;
                   else if(sie==14)
                    price=975;
                   else
                    price=1250;break;
          case 13: if(sie==1)
                    price=85;
                   else if(sie==4)
                    price=320;
                   else
                    price=790;break;
          case 14: if(sie==0.25)
                    price=70;
                   else if(sie==0.5)
                    price=140;
                   else
                    price=250;break;
          case 15: if(sie==0.5)
                    price=130;
                   else
                    price=250;break;
          case 16: if(sie==0.5)
                    price=120;
                   else
                    price=240;break;

          case 17: price=180;break;
          case 18: price=65;break;
          case 19: price=70;break;
          case 20: if(sie==250)
                     price=20;
                   else
                     price=30;break;

    }
      printf("\n Please enter quantity: ");
      scanf("%d",&qty);
      printf("Would you like to order anything else? (y/n): ");
      scanf("%s",quest);
      if(strcmp(quest,"y")==0)
      {
         amount+=(qty*price);
         goto IT;
      }
       else
      {
          amount+=(qty*price);
          printf("\n Number of food items ordered is %d",item_nos);
          printf("\n Thank You %s for your order!!",n[count-1].name);
          printf("\n Your net Bill Amount is:%f tk ",amount);
          printf("\n Please wait while we prepare your food.");
      }

}

int serve()
{

    int i=0;
    if(count==1)

        printf("\n Order no. %d by % s is READY!!",count,n[0].name);
    while(i<(count-1))
    {
        printf("\n Order no. %d by %s is READY!!",i+1,n[i].name);
        printf("\n ENJOY YOUR MEAL!");
        s++;
        i++;
        if(i==(count-1))
        {
            printf("\n Order no. %d by %s is pending...Please Wait",i+1,n[i].name);
            pending++;
        }



    }




}
