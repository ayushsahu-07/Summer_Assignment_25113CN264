//Write a program to Create salary management system.


#include <iostream>
#include <string.h>
using namespace std;

int main() {
    const int MAX = 100;

    int   id[MAX];
    char  name[MAX][50];
    char  dept[MAX][30];
    float basic[MAX];       
    float hra[MAX];        
    float da[MAX];         
    float pf[MAX];         
    float tax[MAX];         
    float gross[MAX];      
    float net[MAX];        
    int   count = 0;

    int choice;

    do {
        cout << "\n====== Salary Management System ======\n";
        cout << "1. Add Employee & Calculate Salary\n";
        cout << "2. Display All Salary Slips\n";
        cout << "3. Search Salary by Employee ID\n";
        cout << "4. Update Basic Salary\n";
        cout << "5. Delete Employee Record\n";
        cout << "6. Display Department-wise Report\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin  >> choice;

        if (choice == 1) {
            if (count == MAX) {
                cout << "Record is full!\n";
            } else {
                cout << "Enter Employee ID : "; cin >> id[count];

                int dup = 0;
                for (int i = 0; i < count; i++) {
                    if (id[i] == id[count]) { dup = 1; break; }
                }
                if (dup) {
                    cout << "ID already exists!\n";
                } else {
                    cout << "Enter Name        : "; cin >> name[count];
                    cout << "Enter Department  : "; cin >> dept[count];
                    cout << "Enter Basic Salary: "; cin >> basic[count];

                    hra[count]   = 0.20f * basic[count];
                    da[count]    = 0.10f * basic[count];
                    pf[count]    = 0.12f * basic[count];
                    tax[count]   = 0.05f * basic[count];
                    gross[count] = basic[count] + hra[count] + da[count];
                    net[count]   = gross[count] - pf[count] - tax[count];

                    count++;
                    cout << "Employee added and salary calculated!\n";
                }
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No records found.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "\n------------------------------------------\n";
                    cout << "           SALARY SLIP\n";
                    cout << "------------------------------------------\n";
                    cout << "ID         : " << id[i]    << "\n";
                    cout << "Name       : " << name[i]  << "\n";
                    cout << "Department : " << dept[i]  << "\n";
                    cout << "------------------------------------------\n";
                    cout << "Basic      : " << basic[i] << "\n";
                    cout << "HRA (20%)  : " << hra[i]   << "\n";
                    cout << "DA  (10%)  : " << da[i]    << "\n";
                    cout << "Gross Pay  : " << gross[i] << "\n";
                    cout << "------------------------------------------\n";
                    cout << "PF  (12%)  : " << pf[i]    << "\n";
                    cout << "Tax  (5%)  : " << tax[i]   << "\n";
                    cout << "------------------------------------------\n";
                    cout << "Net Salary : " << net[i]   << "\n";
                    cout << "------------------------------------------\n";
                }
            }
        }

        else if (choice == 3) {
            int sid;
            cout << "Enter Employee ID to search: "; cin >> sid;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (id[i] == sid) { found = i; break; }
            }
            if (found == -1) {
                cout << "Employee not found.\n";
            } else {
                int i = found;
                cout << "\n------------------------------------------\n";
                cout << "           SALARY SLIP\n";
                cout << "------------------------------------------\n";
                cout << "ID         : " << id[i]    << "\n";
                cout << "Name       : " << name[i]  << "\n";
                cout << "Department : " << dept[i]  << "\n";
                cout << "------------------------------------------\n";
                cout << "Basic      : " << basic[i] << "\n";
                cout << "HRA (20%)  : " << hra[i]   << "\n";
                cout << "DA  (10%)  : " << da[i]    << "\n";
                cout << "Gross Pay  : " << gross[i] << "\n";
                cout << "------------------------------------------\n";
                cout << "PF  (12%)  : " << pf[i]    << "\n";
                cout << "Tax  (5%)  : " << tax[i]   << "\n";
                cout << "------------------------------------------\n";
                cout << "Net Salary : " << net[i]   << "\n";
                cout << "------------------------------------------\n";
            }
        }

        else if (choice == 4) {
            int uid;
            cout << "Enter Employee ID to update: "; cin >> uid;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (id[i] == uid) { found = i; break; }
            }
            if (found == -1) {
                cout << "Employee not found.\n";
            } else {
                cout << "Current Basic Salary: " << basic[found] << "\n";
                cout << "Enter New Basic Salary: "; cin >> basic[found];

                int i = found;
                hra[i]   = 0.20f * basic[i];
                da[i]    = 0.10f * basic[i];
                pf[i]    = 0.12f * basic[i];
                tax[i]   = 0.05f * basic[i];
                gross[i] = basic[i] + hra[i] + da[i];
                net[i]   = gross[i] - pf[i] - tax[i];

                cout << "Salary updated! New Net Salary: " << net[i] << "\n";
            }
        }

        else if (choice == 5) {
            int did;
            cout << "Enter Employee ID to delete: "; cin >> did;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (id[i] == did) { found = i; break; }
            }
            if (found == -1) {
                cout << "Employee not found.\n";
            } else {
                for (int i = found; i < count - 1; i++) {
                    id[i]    = id[i + 1];
                    strcpy(name[i], name[i + 1]);
                    strcpy(dept[i], dept[i + 1]);
                    basic[i] = basic[i + 1];
                    hra[i]   = hra[i + 1];
                    da[i]    = da[i + 1];
                    pf[i]    = pf[i + 1];
                    tax[i]   = tax[i + 1];
                    gross[i] = gross[i + 1];
                    net[i]   = net[i + 1];
                }
                count--;
                cout << "Employee record deleted successfully!\n";
            }
        }

        else if (choice == 6) {
            if (count == 0) {
                cout << "No records found.\n";
            } else {
                char udept[MAX][30];
                int  udeptCount = 0;

                for (int i = 0; i < count; i++) {
                    int exists = 0;
                    for (int j = 0; j < udeptCount; j++) {
                        if (strcmp(dept[i], udept[j]) == 0) { exists = 1; break; }
                    }
                    if (!exists) {
                        strcpy(udept[udeptCount], dept[i]);
                        udeptCount++;
                    }
                }
                
                for (int d = 0; d < udeptCount; d++) {
                    float totalNet = 0;
                    int   empCount = 0;

                    cout << "\n==========================================\n";
                    cout << "Department: " << udept[d] << "\n";
                    cout << "==========================================\n";
                    cout << "ID\tName\t\tBasic\t\tNet Salary\n";
                    cout << "------------------------------------------\n";

                    for (int i = 0; i < count; i++) {
                        if (strcmp(dept[i], udept[d]) == 0) {
                            cout << id[i]    << "\t"
                                 << name[i]  << "\t\t"
                                 << basic[i] << "\t\t"
                                 << net[i]   << "\n";
                            totalNet += net[i];
                            empCount++;
                        }
                    }

                    cout << "------------------------------------------\n";
                    cout << "Total Employees : " << empCount << "\n";
                    cout << "Total Net Payout: " << totalNet << "\n";
                }
            }
        }

        else if (choice != 7) {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    cout << "Exiting system. Goodbye!\n";
    return 0;
}