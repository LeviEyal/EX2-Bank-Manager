
/****************************************************************************
* Eyal Levi ID.203249073
* Assignment number 2
* Bank Manager
****************************************************************************/

#include <stdio.h>
#include "myBank.h"

int main() {

    double amount, interest;
    int account;
    char c = ' ';
    while (c != 'E'){
        printf("Enter the char of operation:\n");
        printf("'O': Open an account\n");
        printf("'B': print balance of an account\n");
        printf("'D': Deposit\n");
        printf("'W': Withdrawal\n");
        printf("'C': Close account\n");
        printf("'I': Add interest to all accounts\n");
        printf("'P': Print all opened accounts\n");
        printf("'E': Close all accounts and exit program\n");
        printf("Your choice: ");
        c = getchar();
        while(getchar()!='\n');
        printf("\n   _______________________________________________________\n  |\n");
        switch (c) {
            case 'O':
                printf("  |   Option 'O': Open bank account:\n");
                printf("  |   Enter initial amount:");
                if(scanf("%lf", &amount) == 1)
                    openAccount(amount);
                else
                    printf("  |   Enter correct amount of money!\n");
                break;

            case 'B':
                printf("  |   Option 'B': Check acoount balance:\n");
                printf("  |   Enter account number: ");
                if(scanf("%d", &account) == 1)
                    printBalance(account);
                else 
                    printf("  |   Enter correct account number!\n");
                break;

            case 'D':
                printf("  |   Option 'D': Deposit to account:\n");    
                printf("  |   Enter account number: ");
                if(scanf("%d", &account) == 1){
                    printf("  |   Enter initial amount: ");
                    if(scanf("%lf", &amount) == 1)
                        deposit(account, amount);
                    else printf("  |   Enter correct amount of money!\n");
                }
                else
                    printf("  |   Enter correct account number!\n");
                break;

            case 'W':
                printf("  |   Option 'W': Wuthdraw from account:\n");
                printf("  |   Enter account number: ");
                scanf("%d", &account);
                printf("  |   Enter initial amount: ");
                scanf("%lf", &amount);
                withdrawal(account, amount);
                break;

            case 'C':
                printf("  |   Option 'C': Close account:\n");
                printf("  |   Enter account number: ");
                scanf("%d", &account);
                closeAccount(account);
                break;

            case 'I':
                printf("  |   Option 'I': Add interest to all opened accounts:\n");
                printf("  |   Enter initial amount: ");
                scanf("%lf", &interest);
                addInterestToAllAccounts(interest);
                break;

            case 'P':
                printf("  |   Option 'P': Print all opened accounts:\n");
                printAll();
                break;

            case 'E':
                printf("  |   Option 'E': Closing all accounts and exit:\n");
                exitProgram();
                break;

            default:
                printf("  |   Type correct option..\n");
                break;
        }
        printf("  |_______________________________________________________\n\n");
    }
    exitProgram(); 
}