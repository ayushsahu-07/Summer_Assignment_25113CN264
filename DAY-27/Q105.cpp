//Write a program to Create student record management system. 

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX = 100;

    int rollNo[MAX];
    char name[MAX][50];
    float marks[MAX];
    char grade[MAX];
    int n = 0; 

    int choice;

    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (n >= MAX) {
                cout << "Record full!\n";
            } else {
                cout << "Enter Roll No: ";
                cin >> rollNo[n];

                int dup = 0;
                for (int i = 0; i < n; i++) {
                    if (rollNo[i] == rollNo[n]) {
                        dup = 1;
                        break;
                    }
                }
                if (dup) {
                    cout << "Roll No already exists!\n";
                } else {
                    cout << "Enter Name: ";
                    cin >> name[n];
                    cout << "Enter Marks (0-100): ";
                    cin >> marks[n];

                    if      (marks[n] >= 90) grade[n] = 'A';
                    else if (marks[n] >= 75) grade[n] = 'B';
                    else if (marks[n] >= 60) grade[n] = 'C';
                    else if (marks[n] >= 45) grade[n] = 'D';
                    else                     grade[n] = 'F';

                    n++;
                    cout << "Student added successfully!\n";
                }
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                cout << "No records found.\n";
            } else {
                cout << "\n--------------------------------------------\n";
                cout << "Roll\tName\t\tMarks\tGrade\n";
                cout << "--------------------------------------------\n";
                for (int i = 0; i < n; i++) {
                    cout << rollNo[i] << "\t"
                         << name[i]   << "\t\t"
                         << marks[i]  << "\t"
                         << grade[i]  << "\n";
                }
                cout << "--------------------------------------------\n";
                cout << "Total Students: " << n << "\n";
            }
        }

        else if (choice == 3) {
            int rno;
            cout << "Enter Roll No to search: ";
            cin >> rno;

            int found = -1;
            for (int i = 0; i < n; i++) {
                if (rollNo[i] == rno) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                cout << "Student not found.\n";
            } else {
                cout << "\nRoll No : " << rollNo[found] << "\n";
                cout << "Name    : " << name[found]   << "\n";
                cout << "Marks   : " << marks[found]  << "\n";
                cout << "Grade   : " << grade[found]  << "\n";
            }
        }

        else if (choice == 4) {
            int rno;
            cout << "Enter Roll No to update: ";
            cin >> rno;

            int found = -1;
            for (int i = 0; i < n; i++) {
                if (rollNo[i] == rno) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                cout << "Student not found.\n";
            } else {
                cout << "Current Marks: " << marks[found] << "\n";
                cout << "Enter new Marks: ";
                cin >> marks[found];

                if      (marks[found] >= 90) grade[found] = 'A';
                else if (marks[found] >= 75) grade[found] = 'B';
                else if (marks[found] >= 60) grade[found] = 'C';
                else if (marks[found] >= 45) grade[found] = 'D';
                else                         grade[found] = 'F';

                cout << "Record updated! New Grade: " << grade[found] << "\n";
            }
        }

        else if (choice == 5) {
            int rno;
            cout << "Enter Roll No to delete: ";
            cin >> rno;

            int found = -1;
            for (int i = 0; i < n; i++) {
                if (rollNo[i] == rno) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                cout << "Student not found.\n";
            } else {

                for (int i = found; i < n - 1; i++) {
                    rollNo[i] = rollNo[i + 1];
                    strcpy(name[i], name[i + 1]);
                    marks[i] = marks[i + 1];
                    grade[i] = grade[i + 1];
                }
                n--;
                cout << "Student deleted successfully!\n";
            }
        }

        else if (choice == 6) {
            cout << "Exiting... Goodbye!\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}