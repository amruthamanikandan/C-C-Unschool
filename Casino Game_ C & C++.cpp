#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    char name[30];
    int dep=0;
    int money=0,bal=0,earn=0;
    int num=0;
    int random=0;
    char op;

    cout<<"------------------------------------------------------"<<endl;
    cout<<"\n \n                   CASINO GAME                    "<<endl;
    cout<<"\n \n-----------------------------------------------------"<<endl;

    cout<<"\nEnter Your Name: ";
    cin>>name;
    cout<<"\nEnter deposit amount($) to play game: ";
    cin>>dep;
    bal=dep;

    cout<<"\n \n-------------------------------------------------------------"<<endl;
    cout<<"\t \t RULES OF THE GAME"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<" 1.Choose any number between 1 to 10"<<endl;
    cout<<" 2.If you win you will get 10 times of the money you bet"<<endl;
    cout<<" 3.If you bet on wrong number you will lose your betting amount"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;

process:
    cout<<"\nYour current balance is $"<<bal<<endl;
    cout<<name<<", Enter your money($) to bet: ";
    cin>>money;
    cout<<"Guess your number to bet between 1 to 10: ";
    cin>>num;

    srand(time(0));
    random=rand()%10+1;
    cout<<"\nThe winning number is: "<<random<<endl;

    if(random==num)
      {
        cout<<"\nCONGRATULATIONS "<<name<<"!"<<endl;
        cout<<"You guessed the correct number!"<<endl;
        earn=money*10;
        cout<<"\nYou earn $"<<earn<<endl;
        bal=bal+earn;
        cout<<"\nYour current balance is $"<<bal;
      }

    else
    {
        cout<<"\nBAD LUCK THIS TIME!! You lost $"<<money<<endl;
        bal=bal-money;
        cout<<name<<", You have $"<<bal<<" left"<<endl;

    }

    cout<<"\n Do you wish to play again? (y/n): ";
    cin>>op;

    if(op=='y')
    {
      if(bal==0)
        cout<<"Oops! You are out of balance. BETTER LUCK NEXT TIME!";
      else
        goto process;
    }

    else
    {
        cout<<"YOU EARN $"<<bal<<endl;
        cout<<"Thank you for playing at CASINO GAME!";
    }



    return 0;
}
