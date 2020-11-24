
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
#define FIRST 901
#define LAST 950
double bank[NUM_OF_ACCOUNTS][FIELDS];

double formatFloatNumber(double num){
    num = (int)(num*100);
    return num/100;
}

void openAccount(double amount){
    if(amount < 1){
        printf("  |   You can't open an account with negativ amount of money!\n");
        printf("  |   Account not opened...\n");
    }
    else{
        for (int  i=0;  i < NUM_OF_ACCOUNTS ; i++){
            if(bank[i][state] == closed){
                bank[i][balance] = formatFloatNumber(amount);
                bank[i][state] = opened;
                printf("  |   Acoount %d opened with amount %.2lf\n", i+FIRST, bank[i][balance]);
                return;
            }
        }
        printf("  |   The bank reached its maximum accounts.. try different bank.\n");
    }
}

void printBalance(int account){
    if(bank[account-FIRST][state] == closed){
        printf("  |   Account %d is not open!\n", account);
    }
    else{
        printf("  |   Account %d balance: %.2lf\n", account, bank[account-FIRST][balance]);
    }
}

void deposit(int account, double amount){
    if(account < FIRST || account > LAST){
        printf("  |   Account number must be 901-950 only! try again..\n");
    }
    else if(amount < 1){
        printf("  |   You can't deposit negativ amount of money!\n");
    }
    else if(bank[account-FIRST][state] == closed){
        printf("  |   Account %d is not open!\n", account);
    }
    else{
        printf("  |   Account number %d: \n", account);
        printf("  |   Old balance: %.2lf\n", bank[account-FIRST][balance]);
        bank[account-FIRST][balance] += amount;
        printf("  |   New balance: %.2lf\n", bank[account-FIRST][balance]);
    }
}

void withdrawal(int account, double amount){
    if(account < FIRST || account > LAST){
        printf("  |   Account number must be 901-950 only! try again..\n");
    }
    else if(bank[account-FIRST][state] == closed){
        printf("  |   Account number %d is closed. try again\n", account);
    }
    else if(amount < 1){
        printf("  |   Amount of money to withdrawal must be positive\n");
    }
    else if(amount > bank[account-FIRST][balance]){
        printf("  |   Not enough money in bank account to withdraw\n");
    }
    else {
        printf("  |   Account number %d: \n", account);
        printf("  |   Old balance: %.2lf\n", bank[account-FIRST][balance]);
        bank[account-FIRST][balance] -= amount;
        printf("  |   New balance: %.2lf\n", bank[account-FIRST][balance]);
    }
}

void closeAccount(int account){
    if(account < FIRST || account > LAST){
        printf("  |   Account number must be 901-950 only! try again..\n");
    }
    else if(bank[account-FIRST][state] == closed){
        printf("  |   Account %d is already closed.\n", account);
    }
    else {
        bank[account-FIRST][balance] = 0;
        bank[account-FIRST][state] = closed;
        printf("  |   Account %d is now closed.\n", account);
    }
}

void addInterestToAllAccounts(double interest){
    if(interest < 0 || interest > 100){
        printf("  |   Interest rate must be 0-100%%.\n");
    }
    else{
        for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
            if(bank[i][state] == opened){
                bank[i][balance] += bank[i][balance]*(interest/100);
            }
        }
    }
}

void printAll(){
    printf("  |   All opened accounts:\n");
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(bank[i][state] == opened){
            printBalance(i+FIRST);
        }
    }
}

void exitProgram(){
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        closeAccount(i+FIRST);
    }
}