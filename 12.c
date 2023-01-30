#include<stdio.h>
#include<stdlib.h>

int PIN = 1882;
int amount = 200000;
int menu()
{
    int userI;
    printf("enter choice\n");
    printf("1:- withdrawMoney\n");
    printf("2:- mini statement\n");
    printf("3:- change pin\n");
    printf("4:- check balance\n");
    printf("5:- exit\n");
    scanf(" %d",&userI);
    return userI;

}
void withdrawMoney(int pastTrans[])
{
    int count = 1;
    int userI;
    do
    {
        if(count > 1)
        {
        printf("insufficient balance\n");
        }
        printf("enter amount:-\n");
        scanf(" %d",&userI);
        if(userI <= amount)
        {
            count = 0;
            amount = amount -userI;
            printf("%d RS withdrawn\n",userI);
            printf("remaining balance %d\n",amount);
            int i = 0;
            while (i<5)
            {
                if(pastTrans[i] == 0)
                {
                    pastTrans[i] = userI;
                    break;
                }
                i=i+1;
            }
            }
        else
        {
            count = count+1;
        }
    } while(count>0);
}
void minist(int pastTrans[])
{
    for(int i = 0; i<5; i =i+1)
    {
        printf("transaction number %d:-%d\n", i+1, pastTrans[i]);
    }
}
void pinChange()
{
    int userI;
    printf("enter current pin");
    scanf(" %d", &userI);
    if (userI == PIN)
    {
        printf("enter new pin\n");
        scanf(" %d", &PIN);
        printf("pin Change\n");
    }
    else
    {
        printf("wrong pin\n");
    }
}
int pinMenu(int pinCount)
{
    int userI;
    if(pinCount < 3)
    {
        printf("wrong pin!!\n");
        printf("available chance %d\n",pinCount);

    }
    printf("enter pin\n");
    scanf(" %d", &userI);
    return userI;
    }
    int main()
    {
        system("cls");
         
         int pastTrans[5] = {0,0,0,0,0};
         int userI;
         int pincount = 3;
         
         while(pincount)
       {
    userI = pinMenu(pincount);
    if(userI == PIN)
    {
        pincount = 0;
        int repeatopt;
    do
    {
         userI = menu();

         switch (userI)
         {
            case 1: withdrawMoney(pastTrans);
                break;
            case 2: minist(pastTrans);
                break;
            case 3: pinChange();
                 break;
            case 4: printf("balence is %d \n", amount);
                break;
            case 5: return 0;
            default: printf("wrong choice\n");
            break; 
         }
     printf("do you want to repeat again?? enter 1\n");
     scanf(" %d", &repeatopt);
      }
      while(repeatopt == 1);
      }
      else
      {
        pincount -= 1;
      }
    }
return 0;
    }