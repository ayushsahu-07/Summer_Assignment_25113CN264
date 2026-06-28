//Write a program to Create employee management system


#include <iostream>
#include <string.h>
using namespace std;

int main() {

    const int MAX = 100;
    int    id[MAX];
    char   name[MAX][50];
    char   dept[MAX][30];
    float  salary[MAX];
    int    count = 0;        

    int choice;

    do {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee Salary\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin  >> choice;
        if (choice == 1) {
            if (count == MAX) {
                cout << "Employee list is full!\n";
            } else {
                cout << "Enter Employee ID   : "; cin >> id[count];

                int dup = 0;
                for (int i = 0; i < count; i++) {
                    if (id[i] == id[count]) { dup = 1; break; }
                }
                if (dup) {
                    cout << "ID already exists!\n";
                } else {
                    cout << "Enter Name          : "; cin >> name[count];
                    cout << "Enter Department    : "; cin >> dept[count];
                    cout << "Enter Salary        : "; cin >> salary[count];
                    count++;
                    cout << "Employee added successfully!\n";
                }
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No employees found.\n";
            } else {
                cout << "\n------------------------------------------------------------\n";
                cout << "ID\tName\t\tDepartment\tSalary\n";
                cout << "------------------------------------------------------------\n";
                for (int i = 0; i < count; i++) {
                    cout << id[i] << "\t"
                         << name[i] << "\t\t"
                         << dept[i] << "\t\t"
                         << salary[i] << "\n";
                }
                cout << "------------------------------------------------------------\n";
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
                cout << "\nID       : " << id[found]     << "\n";
                cout << "Name     : " << name[found]   << "\n";
                cout << "Dept     : " << dept[found]   << "\n";
                cout << "Salary   : " << salary[found] << "\n";
            }
        }

        else if (choice == 4) {
            int uid;
            cout << "Enter Employee ID to update salary: "; cin >> uid;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (id[i] == uid) { found = i; break; }
            }
            if (found == -1) {
                cout << "Employee not found.\n";
            } else {
                cout << "Current Salary: " << salary[found] << "\n";
                cout << "Enter New Salary: "; cin >> salary[found];
                cout << "Salary updated successfully!\n";
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
                    id[i]     = id[i + 1];
                    strcpy(name[i],   name[i + 1]);
                    strcpy(dept[i],   dept[i + 1]);
                    salary[i] = salary[i + 1];
                }
                count--;
                cout << "Employee deleted successfully!\n";
            }
        }

        else if (choice != 6) {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    cout << "Exiting system. Goodbye!\n";
    return 0;
}