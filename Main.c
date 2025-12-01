#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayAllAccounts();

int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("     BANK MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            displayAllAccounts();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createAccount() {
    struct account acc;
    FILE *fp;

    fp = fopen("bankdata.txt", "a");

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter Name: ");
    scanf("%s", acc.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

void depositMoney() {
    FILE *fp;
    struct account acc;
    int accNo, found = 0;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    fp = fopen("bankdata.txt", "r+");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNo) {
            acc.balance += amount;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            printf("Money Deposited Successfully!\n");
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Account Not Found!\n");
    }
}

void withdrawMoney() {
    FILE *fp;
    struct account acc;
    int accNo, found = 0;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    fp = fopen("bankdata.txt", "r+");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNo) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("Withdrawal Successful!\n");
            } else {
                printf("Insufficient Balance!\n");
            }
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Account Not Found!\n");
    }
}

void checkBalance() {
    FILE *fp;
    struct account acc;
    int accNo, found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    fp = fopen("bankdata.txt", "r");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("\nAccount Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Account Not Found!\n");
    }
}

void displayAllAccounts() {
    FILE *fp;
    struct account acc;

    fp = fopen("bankdata.txt", "r");

    printf("\n===== ALL ACCOUNT DETAILS =====\n");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("\nAccount Number: %d\n", acc.accountNumber);
        printf("Name: %s\n", acc.name);
        printf("Balance: %.2f\n", acc.balance);
        printf("------------------------------\n");
    }

    fclose(fp);
}
