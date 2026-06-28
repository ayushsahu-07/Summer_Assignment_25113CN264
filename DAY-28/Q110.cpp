//Write a program to Create bank account system.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX = 100;

    int    accNo[MAX];
    char   name[MAX][50];
    char   type[MAX][20];  
    float  balance[MAX];
    int    totalAcc = 0;

    const int TMAX = 200;
    int   tAcc[TMAX];
    char  tType[TMAX][20];  
    float tAmt[TMAX];
    int   totalTrans = 0;

    int choice;

    do {
        cout << "\n====== BANK ACCOUNT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Transfer Money\n";
        cout << "7. View Transaction History\n";
        cout << "8. Delete Account\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (totalAcc >= MAX) {
                cout << "Bank full! Cannot add more accounts.\n";
            } else {
                cout << "Enter Account Number : "; cin >> accNo[totalAcc];

                int dup = 0;
                for (int i = 0; i < totalAcc; i++)
                    if (accNo[i] == accNo[totalAcc]) { dup = 1; break; }

                if (dup) {
                    cout << "Account number already exists!\n";
                } else {
                    cin.ignore();
                    cout << "Enter Name           : "; cin.getline(name[totalAcc], 50);
                    cout << "Account Type (1-Savings / 2-Current) : ";
                    int t; cin >> t;
                    if (t == 1) strcpy(type[totalAcc], "Savings");
                    else        strcpy(type[totalAcc], "Current");
                    cout << "Enter Opening Balance: "; cin >> balance[totalAcc];

                    if (balance[totalAcc] < 0) {
                        cout << "Balance cannot be negative!\n";
                    } else {
                        cout << "Account created successfully!\n";
                        totalAcc++;
                    }
                }
            }
        }

        else if (choice == 2) {
            if (totalAcc == 0) {
                cout << "No accounts found.\n";
            } else {
                cout << "\n--- All Accounts ---\n";
                cout << "AccNo\tName\t\tType\t\tBalance\n";
                cout << "-----------------------------------------------\n";
                for (int i = 0; i < totalAcc; i++) {
                    cout << accNo[i]    << "\t"
                         << name[i]    << "\t\t"
                         << type[i]    << "\t\t"
                         << balance[i] << "\n";
                }
            }
        }

        else if (choice == 3) {
            int san;
            cout << "Enter Account Number to search: "; cin >> san;
            int found = 0;
            for (int i = 0; i < totalAcc; i++) {
                if (accNo[i] == san) {
                    cout << "\n--- Account Details ---\n";
                    cout << "Account No : " << accNo[i]    << "\n";
                    cout << "Name       : " << name[i]     << "\n";
                    cout << "Type       : " << type[i]     << "\n";
                    cout << "Balance    : Rs." << balance[i] << "\n";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "Account not found.\n";
        }

        else if (choice == 4) {
            int dan; float damt;
            cout << "Enter Account Number : "; cin >> dan;
            int found = -1;
            for (int i = 0; i < totalAcc; i++)
                if (accNo[i] == dan) { found = i; break; }

            if (found == -1) {
                cout << "Account not found.\n";
            } else {
                cout << "Enter Deposit Amount : "; cin >> damt;
                if (damt <= 0) {
                    cout << "Invalid amount!\n";
                } else {
                    balance[found] += damt;
                    tAcc[totalTrans]  = dan;
                    strcpy(tType[totalTrans], "Deposit");
                    tAmt[totalTrans]  = damt;
                    totalTrans++;
                    cout << "Rs." << damt << " deposited. New Balance: Rs." << balance[found] << "\n";
                }
            }
        }

        else if (choice == 5) {
            int wan; float wamt;
            cout << "Enter Account Number  : "; cin >> wan;
            int found = -1;
            for (int i = 0; i < totalAcc; i++)
                if (accNo[i] == wan) { found = i; break; }

            if (found == -1) {
                cout << "Account not found.\n";
            } else {
                cout << "Enter Withdraw Amount : "; cin >> wamt;
                if (wamt <= 0) {
                    cout << "Invalid amount!\n";
                } else if (wamt > balance[found]) {
                    cout << "Insufficient balance! Available: Rs." << balance[found] << "\n";
                } else {
                    balance[found] -= wamt;
                    tAcc[totalTrans]  = wan;
                    strcpy(tType[totalTrans], "Withdraw");
                    tAmt[totalTrans]  = wamt;
                    totalTrans++;
                    cout << "Rs." << wamt << " withdrawn. New Balance: Rs." << balance[found] << "\n";
                }
            }
        }

        else if (choice == 6) {
            int from, to; float tamt;
            cout << "Enter Sender Account No   : "; cin >> from;
            cout << "Enter Receiver Account No : "; cin >> to;
            cout << "Enter Transfer Amount     : "; cin >> tamt;

            int fi = -1, ti = -1;
            for (int i = 0; i < totalAcc; i++) {
                if (accNo[i] == from) fi = i;
                if (accNo[i] == to)   ti = i;
            }

            if (fi == -1)      cout << "Sender account not found.\n";
            else if (ti == -1) cout << "Receiver account not found.\n";
            else if (fi == ti) cout << "Cannot transfer to the same account.\n";
            else if (tamt <= 0) cout << "Invalid amount!\n";
            else if (tamt > balance[fi]) {
                cout << "Insufficient balance! Available: Rs." << balance[fi] << "\n";
            } else {
                balance[fi] -= tamt;
                balance[ti] += tamt;
                tAcc[totalTrans]  = from;
                strcpy(tType[totalTrans], "Transfer-Out");
                tAmt[totalTrans]  = tamt;
                totalTrans++;
                tAcc[totalTrans]  = to;
                strcpy(tType[totalTrans], "Transfer-In");
                tAmt[totalTrans]  = tamt;
                totalTrans++;
                cout << "Rs." << tamt << " transferred successfully!\n";
                cout << name[fi] << " Balance: Rs." << balance[fi] << "\n";
                cout << name[ti] << " Balance: Rs." << balance[ti] << "\n";
            }
        }

        else if (choice == 7) {
            int han;
            cout << "Enter Account Number : "; cin >> han;
            int exists = 0, hasT = 0;
            for (int i = 0; i < totalAcc; i++)
                if (accNo[i] == han) { exists = 1; break; }

            if (!exists) {
                cout << "Account not found.\n";
            } else {
                cout << "\n--- Transaction History for Acc " << han << " ---\n";
                cout << "Type\t\tAmount\n";
                cout << "-------------------------\n";
                for (int i = 0; i < totalTrans; i++) {
                    if (tAcc[i] == han) {
                        cout << tType[i] << "\t\tRs." << tAmt[i] << "\n";
                        hasT = 1;
                    }
                }
                if (!hasT) cout << "No transactions yet.\n";
            }
        }

        else if (choice == 8) {
            int dan;
            cout << "Enter Account Number to delete: "; cin >> dan;
            int di = -1;
            for (int i = 0; i < totalAcc; i++)
                if (accNo[i] == dan) { di = i; break; }

            if (di == -1) {
                cout << "Account not found.\n";
            } else if (balance[di] > 0) {
                cout << "Cannot delete! Account has balance Rs." << balance[di] << ". Withdraw first.\n";
            } else {
                for (int i = di; i < totalAcc - 1; i++) {
                    accNo[i]   = accNo[i+1];
                    balance[i] = balance[i+1];
                    strcpy(name[i],    name[i+1]);
                    strcpy(type[i],    type[i+1]);
                }
                totalAcc--;
                cout << "Account deleted successfully!\n";
            }
        }

        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    cout << "Thank you for using the Bank System. Goodbye!\n";
    return 0;
}

