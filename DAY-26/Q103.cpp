//Write a program to Create ATM simulation

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // --- Account Data ---
    char accountNumber[20] = "1234567890";
    char pin[5]            = "7890";
    char name[50]          = "Ayush Sahu";
    float balance          = 25000.00;

    // --- Input Variables ---
    char enteredAccount[20];
    char enteredPin[5];
    int choice;
    float amount;

    int attempts = 0;
    int maxAttempts = 3;
    int loggedIn = 0;

    cout << "============================\n";
    cout << "       WELCOME TO ATM       \n";
    cout << "============================\n\n";

    // --- Step 1: Account Number ---
    cout << "Enter Account Number: ";
    cin >> enteredAccount;

    if (strcmp(enteredAccount, accountNumber) != 0) {
        cout << "\nAccount not found. Exiting.\n";
        return 0;
    }

    // --- Step 2: PIN Verification (max 3 tries) ---
    while (attempts < maxAttempts) {
        cout << "Enter PIN: ";
        cin >> enteredPin;
        attempts++;

        if (strcmp(enteredPin, pin) == 0) {
            loggedIn = 1;
            break;
        } else {
            if (attempts < maxAttempts) {
                cout << "Wrong PIN! " << (maxAttempts - attempts) << " attempt(s) left.\n";
            }
        }
    }

    if (!loggedIn) {
        cout << "\nCard blocked due to too many wrong PIN attempts.\n";
        cout << "Please contact your bank.\n";
        return 0;
    }

    cout << "\nLogin Successful!\n";
    cout << "Welcome, " << name << "!\n";

    // --- Step 3: ATM Menu ---
    do {
        cout << "\n============================\n";
        cout << "         ATM MENU           \n";
        cout << "============================\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "----------------------------\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // --- Balance Enquiry ---
            cout << "\n----------------------------\n";
            cout << "Account Holder : " << name << "\n";
            cout << "Account Number : " << accountNumber << "\n";
            cout << "Balance        : Rs. " << balance << "\n";
            cout << "----------------------------\n";

        } else if (choice == 2) {
            // --- Deposit ---
            cout << "\nEnter amount to deposit: Rs. ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount! Must be greater than 0.\n";
            } else if (amount > 100000) {
                cout << "Deposit limit exceeded! Max deposit is Rs. 1,00,000.\n";
            } else {
                balance += amount;
                cout << "\nRs. " << amount << " deposited successfully!\n";
                cout << "New Balance: Rs. " << balance << "\n";
            }

        } else if (choice == 3) {
            // --- Withdrawal ---
            cout << "\nEnter amount to withdraw: Rs. ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount! Must be greater than 0.\n";
            } else if ((int)amount % 100 != 0) {
                cout << "Amount must be a multiple of 100.\n";
            } else if (amount > 10000) {
                cout << "Withdrawal limit exceeded! Max withdrawal is Rs. 10,000.\n";
            } else if (amount > balance) {
                cout << "Insufficient balance!\n";
                cout << "Available Balance: Rs. " << balance << "\n";
            } else {
                balance -= amount;
                cout << "\nPlease collect your cash.\n";
                cout << "Rs. " << amount << " withdrawn successfully!\n";
                cout << "Remaining Balance: Rs. " << balance << "\n";
            }

        } else if (choice == 4) {
            cout << "\nThank you for using the ATM.\n";
            cout << "Please collect your card.\n";
            cout << "Goodbye, " << name << "!\n";

        } else {
            cout << "Invalid choice! Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}