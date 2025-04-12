// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_ACCOUNTS 100

// struct Transaction {
//     float amount;
//     char type; // 'D' for deposit, 'W' for withdrawal
// };

// struct BankAccount {
//     int accountNumber;
//     char name[50];
//     float balance;
//     struct Transaction transactions[100];
//     int transactionCount;
//     char password[20];
// };

// struct Bank {
//     struct BankAccount accounts[MAX_ACCOUNTS];
//     int accountCount;
// };

// // Function prototypes
// int createAccount(struct Bank* bank);
// int authenticate(struct Bank* bank, int accountNumber, char* password);
// void deposit(struct Bank* bank, int accountNumber);
// void withdraw(struct Bank* bank, int accountNumber);
// void displayAccountDetails(struct Bank* bank, int accountNumber);
// void saveAccountDetails(struct Bank* bank);
// void loadAccountDetails(struct Bank* bank);
// void displayTransactionHistory(struct Bank* bank, int accountNumber);
// void showAccountList(struct Bank* bank);
// void removeAccount(struct Bank* bank, int accountNumber);

// int main() {
//     struct Bank bank;
//     bank.accountCount = 0;
    
//     loadAccountDetails(&bank); // Load data from file

//     int choice;
//     do {
//         printf("\n*** Banking Management System ***\n");
//         printf("1. Create Account\n");
//         printf("2. Deposit Money\n");
//         printf("3. Withdraw Money\n");
//         printf("4. Display Account Details\n");
//         printf("5. Transaction History\n");
//         printf("6. Show Account List\n");
//         printf("7. Remove Account\n");
//         printf("8. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         int accountNumber;
//         switch (choice) {
//             case 1:
//                 createAccount(&bank);
//                 break;
//             case 2:
//                 printf("Enter Account Number: ");
//                 scanf("%d", &accountNumber);
//                 deposit(&bank, accountNumber);
//                 break;
//             case 3:
//                 printf("Enter Account Number: ");
//                 scanf("%d", &accountNumber);
//                 withdraw(&bank, accountNumber);
//                 break;
//             case 4:
//                 printf("Enter Account Number: ");
//                 scanf("%d", &accountNumber);
//                 displayAccountDetails(&bank, accountNumber);
//                 break;
//             case 5:
//                 printf("Enter Account Number: ");
//                 scanf("%d", &accountNumber);
//                 displayTransactionHistory(&bank, accountNumber);
//                 break;
//             case 6:
//                 showAccountList(&bank);
//                 break;
//             case 7:
//                 printf("Enter Account Number: ");
//                 scanf("%d", &accountNumber);
//                 removeAccount(&bank, accountNumber);
//                 break;
//             case 8:
//                 saveAccountDetails(&bank); // Save data before exiting
//                 printf("Exiting the program. Thank you!\n");
//                 break;
//             default:
//                 printf("Invalid choice. Please enter a valid option.\n");
//         }
//     } while (choice != 8);

//     return 0;
// }

// // ---------------------------
// // ✅ Create Account Function
// // ---------------------------
// int createAccount(struct Bank* bank) {
//     if (bank->accountCount >= MAX_ACCOUNTS) {
//         printf("Cannot create more accounts. Maximum limit reached.\n");
//         return -1;
//     }

//     struct BankAccount newAccount;
//     newAccount.accountNumber = bank->accountCount + 1;
//     printf("Enter Name: ");
//     scanf("%s", newAccount.name);

//     printf("Set Password: ");
//     scanf("%s", newAccount.password);
//     newAccount.balance = 0;
//     newAccount.transactionCount = 0;

//     bank->accounts[bank->accountCount] = newAccount;
//     bank->accountCount++;

//     printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
//     return 0;
// }

// // ---------------------------
// // ✅ Authenticate User
// // ---------------------------
// int authenticate(struct Bank* bank, int accountNumber, char* password) {
//     if (accountNumber < 1 || accountNumber > bank->accountCount) {
//         printf("Invalid account number.\n");
//         return 0;
//     }

//     int index = accountNumber - 1;
//     if (strcmp(bank->accounts[index].password, password) == 0) {
//         return 1; // Authentication successful
//     }

//     printf("Incorrect password.\n");
//     return 0;
// }

// // ---------------------------
// // ✅ Deposit Money
// // ---------------------------
// void deposit(struct Bank* bank, int accountNumber) {
//     char password[20];
//     printf("Enter Password: ");
//     scanf("%s", password);

//     if (!authenticate(bank, accountNumber, password)) {
//         printf("Authentication failed. Deposit aborted.\n");
//         return;
//     }

//     float amount;
//     printf("Enter Amount to Deposit: ");
//     scanf("%f", &amount);

//     int index = accountNumber - 1;
//     bank->accounts[index].balance += amount;

//     // Add transaction record
//     bank->accounts[index].transactions[bank->accounts[index].transactionCount].amount = amount;
//     bank->accounts[index].transactions[bank->accounts[index].transactionCount].type = 'D';
//     bank->accounts[index].transactionCount++;

//     printf("Amount deposited successfully! Updated balance: %.2f\n", bank->accounts[index].balance);
// }

// // ---------------------------
// // ✅ Withdraw Money
// // ---------------------------
// void withdraw(struct Bank* bank, int accountNumber) {
//     char password[20];
//     printf("Enter Password: ");
//     scanf("%s", password);

//     if (!authenticate(bank, accountNumber, password)) {
//         printf("Authentication failed. Withdrawal aborted.\n");
//         return;
//     }

//     float amount;
//     printf("Enter Amount to Withdraw: ");
//     scanf("%f", &amount);

//     int index = accountNumber - 1;
//     if (amount > bank->accounts[index].balance) {
//         printf("Insufficient balance. Withdrawal failed.\n");
//         return;
//     }

//     bank->accounts[index].balance -= amount;

//     // Add transaction record
//     bank->accounts[index].transactions[bank->accounts[index].transactionCount].amount = amount;
//     bank->accounts[index].transactions[bank->accounts[index].transactionCount].type = 'W';
//     bank->accounts[index].transactionCount++;

//     printf("Amount withdrawn successfully! Updated balance: %.2f\n", bank->accounts[index].balance);
// }

// // ---------------------------
// // ✅ Display Account Details
// // ---------------------------
// void displayAccountDetails(struct Bank* bank, int accountNumber) {
//     char password[20];
//     printf("Enter Password: ");
//     scanf("%s", password);

//     if (!authenticate(bank, accountNumber, password)) {
//         printf("Authentication failed. Cannot display details.\n");
//         return;
//     }

//     int index = accountNumber - 1;
//     printf("\n--- Account Details ---\n");
//     printf("Account Number: %d\n", bank->accounts[index].accountNumber);
//     printf("Name: %s\n", bank->accounts[index].name);
//     printf("Balance: %.2f\n", bank->accounts[index].balance);
// }

// // ---------------------------
// // ✅ Save Account Data to File
// // ---------------------------
// void saveAccountDetails(struct Bank* bank) {
//     FILE *fp = fopen("account_data.txt", "w");
//     if (fp == NULL) {
//         printf("Error saving account data.\n");
//         return;
//     }

//     fwrite(bank, sizeof(struct Bank), 1, fp);
//     fclose(fp);
// }

// // ---------------------------
// // ✅ Load Account Data from File
// // ---------------------------
// void loadAccountDetails(struct Bank* bank) {
//     FILE *fp = fopen("account_data.txt", "r");
//     if (fp == NULL) {
//         printf("No previous data found. Starting fresh.\n");
//         return;
//     }

//     fread(bank, sizeof(struct Bank), 1, fp);
//     fclose(fp);
// }

// // ---------------------------
// // ✅ Display Transaction History
// // ---------------------------
// void displayTransactionHistory(struct Bank* bank, int accountNumber) {
//     char password[20];
//     printf("Enter Password: ");
//     scanf("%s", password);

//     if (!authenticate(bank, accountNumber, password)) {
//         printf("Authentication failed. Cannot display transaction history.\n");
//         return;
//     }

//     int index = accountNumber - 1;
//     printf("\n--- Transaction History for Account %d ---\n", accountNumber);
//     for (int i = 0; i < bank->accounts[index].transactionCount; i++) {
//         printf("Type: %c, Amount: %.2f\n",
//                bank->accounts[index].transactions[i].type,
//                bank->accounts[index].transactions[i].amount);
//     }
// }

// // ---------------------------
// // ✅ Show All Accounts
// // ---------------------------
// void showAccountList(struct Bank* bank) {
//     if (bank->accountCount == 0) {
//         printf("No accounts available.\n");
//         return;
//     }
//     printf("\n--- List of All Accounts ---\n");
//     for (int i = 0; i < bank->accountCount; i++) {
//         printf("Account Number: %d, Name: %s, Balance: %.2f\n",
//                bank->accounts[i].accountNumber,
//                bank->accounts[i].name,
//                bank->accounts[i].balance);
//     }
// }

// // ---------------------------
// // ✅ Remove Account
// // ---------------------------
// void removeAccount(struct Bank* bank, int accountNumber) {
//     char password[20];
//     printf("Enter Password: ");
//     scanf("%s", password);

//     if (!authenticate(bank, accountNumber, password)) {
//         printf("Authentication failed. Cannot remove account.\n");
//         return;
//     }

//     int index = accountNumber - 1;
//     for (int i = index; i < bank->accountCount - 1; i++) {
//         bank->accounts[i] = bank->accounts[i + 1];
//     }

//     bank->accountCount--;
//     printf("Account removed successfully.\n");
// }





/////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Transaction {
    float amount;
    char type; // 'D' for deposit, 'W' for withdrawal
};

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
    struct Transaction transactions[100];
    int transactionCount;
    char password[20];
};

struct Bank {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int accountCount;
};

// Function prototypes
int createAccount(struct Bank* bank);
int authenticate(struct Bank* bank, int accountNumber, char* password);
void deposit(struct Bank* bank, int accountNumber);
void withdraw(struct Bank* bank, int accountNumber);
void displayAccountDetails(struct Bank* bank, int accountNumber);
void saveAccountDetails(struct Bank* bank);
void loadAccountDetails(struct Bank* bank);
void displayTransactionHistory(struct Bank* bank, int accountNumber);
void showAccountList(struct Bank* bank);
void removeAccount(struct Bank* bank, int accountNumber);

int main() {
    struct Bank bank;
    bank.accountCount = 0;

    loadAccountDetails(&bank); // Load data from file

    int choice;
    do {
        printf("\n*** Banking Management System ***\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. Transaction History\n");
        printf("6. Show Account List\n");
        printf("7. Remove Account\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int accountNumber;
        switch (choice) {
            case 1:
                createAccount(&bank);
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                deposit(&bank, accountNumber);
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                withdraw(&bank, accountNumber);
                break;
            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                displayAccountDetails(&bank, accountNumber);
                break;
            case 5:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                displayTransactionHistory(&bank, accountNumber);
                break;
            case 6:
                showAccountList(&bank);
                break;
            case 7:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                removeAccount(&bank, accountNumber);
                break;
            case 8:
                saveAccountDetails(&bank); // Save data before exiting
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}

// ---------------------------
// ✅ Create Account Function
// ---------------------------
int createAccount(struct Bank* bank) {
    if (bank->accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return -1;
    }

    struct BankAccount newAccount;
    newAccount.accountNumber = bank->accountCount + 1;
    printf("Enter Name: ");
    scanf("%s", newAccount.name);

    printf("Set Password: ");
    scanf("%s", newAccount.password);
    newAccount.balance = 0;
    newAccount.transactionCount = 0;

    bank->accounts[bank->accountCount] = newAccount;
    bank->accountCount++;

    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
    return 0;
}

// ---------------------------
// ✅ Authenticate User
// ---------------------------
int authenticate(struct Bank* bank, int accountNumber, char* password) {
    if (accountNumber < 1 || accountNumber > bank->accountCount) {
        printf("Invalid account number.\n");
        return 0;
    }

    int index = accountNumber - 1;
    if (strcmp(bank->accounts[index].password, password) == 0) {
        return 1; // Authentication successful
    }

    printf("Incorrect password.\n");
    return 0;
}

// ---------------------------
// ✅ Deposit Money
// ---------------------------
void deposit(struct Bank* bank, int accountNumber) {
    char password[20];
    printf("Enter Password: ");
    scanf("%s", password);

    if (!authenticate(bank, accountNumber, password)) {
        printf("Authentication failed. Deposit aborted.\n");
        return;
    }

    float amount;
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    int index = accountNumber - 1;
    bank->accounts[index].balance += amount;

    // Add transaction record
    bank->accounts[index].transactions[bank->accounts[index].transactionCount].amount = amount;
    bank->accounts[index].transactions[bank->accounts[index].transactionCount].type = 'D';
    bank->accounts[index].transactionCount++;

    printf("Amount deposited successfully! Updated balance: %.2f\n", bank->accounts[index].balance);
}

// ---------------------------
// ✅ Withdraw Money
// ---------------------------
void withdraw(struct Bank* bank, int accountNumber) {
    char password[20];
    printf("Enter Password: ");
    scanf("%s", password);

    if (!authenticate(bank, accountNumber, password)) {
        printf("Authentication failed. Withdrawal aborted.\n");
        return;
    }

    float amount;
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    int index = accountNumber - 1;
    if (amount > bank->accounts[index].balance) {
        printf("Insufficient balance. Withdrawal failed.\n");
        return;
    }

    bank->accounts[index].balance -= amount;

    // Add transaction record
    bank->accounts[index].transactions[bank->accounts[index].transactionCount].amount = amount;
    bank->accounts[index].transactions[bank->accounts[index].transactionCount].type = 'W';
    bank->accounts[index].transactionCount++;

    printf("Amount withdrawn successfully! Updated balance: %.2f\n", bank->accounts[index].balance);
}

// ---------------------------
// ✅ Display Account Details
// ---------------------------
void displayAccountDetails(struct Bank* bank, int accountNumber) {
    char password[20];
    printf("Enter Password: ");
    scanf("%s", password);

    if (!authenticate(bank, accountNumber, password)) {
        printf("Authentication failed. Cannot display details.\n");
        return;
    }

    int index = accountNumber - 1;
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", bank->accounts[index].accountNumber);
    printf("Name: %s\n", bank->accounts[index].name);
    printf("Balance: %.2f\n", bank->accounts[index].balance);
}

// ---------------------------
// ✅ Save Account Data to File (Binary)
// ---------------------------
void saveAccountDetails(struct Bank* bank) {
    FILE *fp = fopen("account_data.bin", "wb");  // Write Binary
    if (fp == NULL) {
        printf("Error saving account data.\n");
        return;
    }

    fwrite(bank, sizeof(struct Bank), 1, fp);
    fclose(fp);
}

// ---------------------------
// ✅ Load Account Data from File (Binary)
// ---------------------------
void loadAccountDetails(struct Bank* bank) {
    FILE *fp = fopen("account_data.bin", "rb");  // Read Binary
    if (fp == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    fread(bank, sizeof(struct Bank), 1, fp);
    fclose(fp);
}

// ---------------------------
// ✅ Display Transaction History
// ---------------------------
void displayTransactionHistory(struct Bank* bank, int accountNumber) {
    char password[20];
    printf("Enter Password: ");
    scanf("%s", password);

    if (!authenticate(bank, accountNumber, password)) {
        printf("Authentication failed. Cannot display transaction history.\n");
        return;
    }

    int index = accountNumber - 1;
    printf("\n--- Transaction History for Account %d ---\n", accountNumber);
    for (int i = 0; i < bank->accounts[index].transactionCount; i++) {
        printf("Type: %c, Amount: %.2f\n",
               bank->accounts[index].transactions[i].type,
               bank->accounts[index].transactions[i].amount);
    }
}

// ---------------------------
// ✅ Show All Accounts
// ---------------------------
void showAccountList(struct Bank* bank) {
    if (bank->accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n--- List of All Accounts ---\n");
    for (int i = 0; i < bank->accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n",
               bank->accounts[i].accountNumber,
               bank->accounts[i].name,
               bank->accounts[i].balance);
    }
}

// ---------------------------
// ✅ Remove Account
// ---------------------------
void removeAccount(struct Bank* bank, int accountNumber) {
    char password[20];
    printf("Enter Password: ");
    scanf("%s", password);

    if (!authenticate(bank, accountNumber, password)) {
        printf("Authentication failed. Cannot remove account.\n");
        return;
    }

    int index = accountNumber - 1;
    for (int i = index; i < bank->accountCount - 1; i++) {
        bank->accounts[i] = bank->accounts[i + 1];
    }

    bank->accountCount--;
    printf("Account removed successfully.\n");
}
