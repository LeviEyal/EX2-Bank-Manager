
/****************************************************************************
* Eyal Levi ID.203249073
* Assignment number 2
* Bank Manager
****************************************************************************/

#include <stdio.h>
#include "myBank.h"

int main() {
    char c = ' ';
    while (c != EOF){
        
        printf("\nPlease choose a transaction type:\n");
        printf(" O-Open Account\n");
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdrawal\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");
        scanf(" %c", &c);
        
        switch (c) {
            case 'O':
                openAccount(); break;
            case 'B':
                printBalance(); break;
            case 'D':
                deposit(); break;
            case 'W':
                withdrawal(); break;
            case 'C':
                closeAccount(); break;
            case 'I':
                addInterestToAllAccounts(); break;
            case 'P':
                printAll(); break;
            case 'E':
                exitProgram(); return 0; break;
            default:
                printf("Invalid transaction type\n"); break;
        }
    }
}