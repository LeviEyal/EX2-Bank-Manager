
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
int account, interest;
double amount;

double formatFloatNumber(double num){
    num = (int)(num*100);
    return num/100;
}

void openAccount(){
    double amount;
    printf("Please enter amount for deposit: ");
    if(scanf("%lf", &amount) != 1)
        printf("Failed to read the amount\n");
    else if(amount < 1){
        printf("Invalid Amount\n");
    }
    else{
        for (int  i=0;  i < NUM_OF_ACCOUNTS ; i++){
            if(bank[i][state] == closed){
                bank[i][balance] = formatFloatNumber(amount);
                bank[i][state] = opened;
                printf("New account number is: %d \n", i+FIRST);
                return;
            }
        }
    }
}

void printBalance(){
    int account;
    printf("Please enter account number: ");
    if(scanf("%d", &account) != 1)
        printf("Failed to read the account number\n");
    else if(account < FIRST || account > LAST){
        printf("Invalid account number\n");
    }
    else if(bank[account-FIRST][state] == closed){
        printf("This account is closed\n");
    }
    else{
        printf("The balance of account number %d is: %.2lf\n", account, bank[account-FIRST][balance]);
    }
}

void deposit() {          
    printf("Please enter account number: ");
    if(scanf(" %d", &account) != 1){
        printf("Failed to read the account number\n");
        return;
    }
    else if(account < FIRST || account > LAST){
        printf("Invalid account number\n");
        return;
    }
    else if(bank[account-FIRST][state] == closed){
        printf("This account is closed\n");
        return;
    }
    printf("Please enter the amount to deposit: ");
    if(scanf(" %lf", &amount) != 1){
        printf("Failed to read the amount\n");
    }
    else if(amount < 0){
        printf("Cannot deposit a negative amount\n");
    }
    else{
        bank[account-FIRST][balance] += amount;
        printf("The new balance is: %.2lf\n", bank[account-FIRST][balance]);
    }
}

void withdrawal(){
    printf("Please enter account number: ");
    if(scanf(" %d", &account) != 1){
        printf("Failed to read the account number\n");
        return;
    }
    else if(account < FIRST || account > LAST){
        printf("Invalid account number\n");
        return;
    }
    else if(bank[account-FIRST][state] == closed){
        printf("This account is closed\n");
        return;
    }
    printf("Please enter the amount to withdraw: ");
    if(scanf(" %lf", &amount) != 1){
        printf("Failed to read the amount\n");
    }
    else if(amount > bank[account-FIRST][balance]){
        printf("Cannot withdraw more than the balance\n");
    }
    else {
        bank[account-FIRST][balance] -= amount;
        printf("The new balance is: %.2lf\n", bank[account-FIRST][balance]);
    }
}

void closeAccount(){
    printf("Please enter account number: ");
    if(scanf(" %d", &account) != 1){
        printf("Failed to read the account number\n");
    }
    else if(account < FIRST || account > LAST){
        printf("Invalid account number\n");
    }
    else if(bank[account-FIRST][state] == closed){
        printf("This account is already closed\n");
    }
    else {
        bank[account-FIRST][balance] = 0;
        bank[account-FIRST][state] = closed;
        printf("Closed account number %d\n", account);
    }
}

void addInterestToAllAccounts(){
    printf("Please enter interest rate: ");
    if(scanf(" %d", &interest) != 1){
        printf("Failed to read the interest rate\n");
    }
    else if(interest < 0 || interest > 100){
        printf("Invalid interest rate\n");
    }
    else{
        for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
            if(bank[i][state] == opened){
                bank[i][balance] += bank[i][balance]*(interest/100.0);
            }
        }
    }
}

void printAll(){
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(bank[i][state] == opened){
            printf("The balance of account number %d is: %.2lf\n", i+FIRST, bank[i][balance]);
        }
    }
}

void exitProgram(){
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(bank[i][state] == opened){
            bank[i][balance] = 0;
            bank[i][state] = closed;
        }
    }
}