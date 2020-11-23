
/****************************************************************************
* Eyal Levi ID.203249073
* Assignment number 2
* Bank Manager
****************************************************************************/

#include <stdio.h>
#include "myBank.h"

enum states{closed=0, opened=1};
enum fields{balance=0, state=1};
#define NUM_OF_ACCOUNTS 50
#define FIELDS 2
double bank[NUM_OF_ACCOUNTS][FIELDS];

double formatNumbers(double num){
    num = (int)(num*100);
    return num/100;
}
void open(double amount){
    for (int  i=0;  i < NUM_OF_ACCOUNTS ; i++){
        if(bank[i][state] == closed){
            bank[i][balance] = formatNumbers(amount);
            bank[i][state] = opened;
            printf("  |   Acoount %d opened with amount %.2lf\n", i+901, bank[i][balance]);
            return;
        }
    }
}

void printBalance(int account){
    if(bank[account-901][state] == opened)
        printf("  |   Account %d balance: %.2lf\n", account, bank[account-901][balance]);
}

void deposit(int account, double amount){
    if(bank[account-901][state] == opened){
        printf("  |   Old balance: %.2lf\n", bank[account-901][balance]);
        bank[account-901][balance] += amount;
        printf("  |   New balance: %.2lf\n", bank[account-901][balance]);
    }
}

void withdrawal(int account, double amount){
    if(account < 901 || account > 950){
        printf("  |   Account number must be 901-950 only! try again..\n");
    }
    else if(amount < 1){
        printf("  |   Amount of money to withdrawal must be positive\n");
    }
    else if(bank[account-901][state] == closed){
        printf("  |   Account number %d is closed. try again\n", account);
    }
    else if(amount > bank[account-901][balance]){
        printf("  |   Not enough money in bank account to withdraw\n");
    }
    else {
        printf("  |   Old balance: %.2lf\n", bank[account-901][balance]);
        bank[account-901][balance] -= amount;
        printf("  |   New balance: %.2lf\n", bank[account-901][balance]);
    }
}

void close(int account){
    if(bank[account-901][state] == opened){
        bank[account-901][balance] = 0;
        bank[account-901][state] = closed;
    }
}

void addInterest(double interest){
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(bank[i][state] == opened){
            bank[i][balance] += bank[i][balance]*(interest/100);
        }
    }
}

void printAll(){
    printf("  |   All opened accounts:\n");
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(bank[i][state] == opened){
            printf("  |   Account %d: balance: %.2lf\n", 901+i, bank[i][balance]);
        }
    }
}

void exitProgram(){
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        close(i);
    }
}