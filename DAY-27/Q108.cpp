//Write a program to Create marksheet generation system. 


#include <iostream>
#include <string.h>
using namespace std;

int main() {
    const int MAX      = 100;
    const int SUBJECTS = 5;

    int   rollNo[MAX];
    char  name[MAX][50];
    char  sname[SUBJECTS][30] = {"Maths", "Science", "English", "Hindi", "Computer"};
    int   marks[MAX][SUBJECTS];
    int   total[MAX];
    float percent[MAX];
    char  grade[MAX];       
    char  result[MAX][5];   
    int   count = 0;

    int choice;

    do {
        cout << "\n====== Marksheet Generation System ======\n";
        cout << "1. Add Student & Enter Marks\n";
        cout << "2. Generate Marksheet (Single Student)\n";
        cout << "3. Display All Marksheets\n";
        cout << "4. Search by Roll Number\n";
        cout << "5. Update Marks\n";
        cout << "6. Delete Student Record\n";
        cout << "7. Class Topper\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin  >> choice;

        if (choice == 1) {
            if (count == MAX) {
                cout << "Student list is full!\n";
            } else {
                cout << "Enter Roll Number : "; cin >> rollNo[count];

                int dup = 0;
                for (int i = 0; i < count; i++) {
                    if (rollNo[i] == rollNo[count]) { dup = 1; break; }
                }
                if (dup) {
                    cout << "Roll number already exists!\n";
                } else {
                    cout << "Enter Name        : "; cin >> name[count];

                    int tot = 0;
                    int fail = 0;
                    cout << "Enter marks out of 100 for each subject:\n";
                    for (int j = 0; j < SUBJECTS; j++) {
                        cout << "  " << sname[j] << " : ";
                        cin  >> marks[count][j];

                        if (marks[count][j] < 0)   marks[count][j] = 0;
                        if (marks[count][j] > 100)  marks[count][j] = 100;

                        if (marks[count][j] < 33) fail = 1;
                        tot += marks[count][j];
                    }

                    total[count]   = tot;
                    percent[count] = tot;
                    if (fail) {
                        grade[count] = 'F';
                        strcpy(result[count], "Fail");
                    } else if (percent[count] >= 90) {
                        grade[count] = 'A';
                        strcpy(result[count], "Pass");
                    } else if (percent[count] >= 75) {
                        grade[count] = 'B';
                        strcpy(result[count], "Pass");
                    } else if (percent[count] >= 60) {
                        grade[count] = 'C';
                        strcpy(result[count], "Pass");
                    } else if (percent[count] >= 33) {
                        grade[count] = 'D';
                        strcpy(result[count], "Pass");
                    } else {
                        grade[count] = 'F';
                        strcpy(result[count], "Fail");
                    }

                    count++;
                    cout << "Student added successfully!\n";
                }
            }
        }

        else if (choice == 2) {
            int rno;
            cout << "Enter Roll Number: "; cin >> rno;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (rollNo[i] == rno) { found = i; break; }
            }
            if (found == -1) {
                cout << "Student not found.\n";
            } else {
                int i = found;
                cout << "\n============================================\n";
                cout << "              MARKSHEET\n";
                cout << "============================================\n";
                cout << "Roll No   : " << rollNo[i] << "\n";
                cout << "Name      : " << name[i]   << "\n";
                cout << "--------------------------------------------\n";
                cout << "Subject\t\tMarks\t\tStatus\n";
                cout << "--------------------------------------------\n";
                for (int j = 0; j < SUBJECTS; j++) {
                    cout << sname[j] << "\t\t"
                         << marks[i][j] << "\t\t"
                         << (marks[i][j] >= 33 ? "Pass" : "Fail") << "\n";
                }
                cout << "--------------------------------------------\n";
                cout << "Total     : " << total[i]              << " / " << SUBJECTS * 100 << "\n";
                cout << "Percentage: " << percent[i]            << " %\n";
                cout << "Grade     : " << grade[i]              << "\n";
                cout << "Result    : " << result[i]             << "\n";
                cout << "============================================\n";
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                cout << "No records found.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "\n============================================\n";
                    cout << "              MARKSHEET\n";
                    cout << "============================================\n";
                    cout << "Roll No   : " << rollNo[i] << "\n";
                    cout << "Name      : " << name[i]   << "\n";
                    cout << "--------------------------------------------\n";
                    cout << "Subject\t\tMarks\t\tStatus\n";
                    cout << "--------------------------------------------\n";
                    for (int j = 0; j < SUBJECTS; j++) {
                        cout << sname[j] << "\t\t"
                             << marks[i][j] << "\t\t"
                             << (marks[i][j] >= 33 ? "Pass" : "Fail") << "\n";
                    }
                    cout << "--------------------------------------------\n";
                    cout << "Total     : " << total[i]   << " / " << SUBJECTS * 100 << "\n";
                    cout << "Percentage: " << percent[i] << " %\n";
                    cout << "Grade     : " << grade[i]   << "\n";
                    cout << "Result    : " << result[i]  << "\n";
                    cout << "============================================\n";
                }
            }
        }

        else if (choice == 4) {
            int rno;
            cout << "Enter Roll Number to search: "; cin >> rno;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (rollNo[i] == rno) { found = i; break; }
            }
            if (found == -1) {
                cout << "Student not found.\n";
            } else {
                int i = found;
                cout << "\n============================================\n";
                cout << "              MARKSHEET\n";
                cout << "============================================\n";
                cout << "Roll No   : " << rollNo[i] << "\n";
                cout << "Name      : " << name[i]   << "\n";
                cout << "--------------------------------------------\n";
                cout << "Subject\t\tMarks\t\tStatus\n";
                cout << "--------------------------------------------\n";
                for (int j = 0; j < SUBJECTS; j++) {
                    cout << sname[j] << "\t\t"
                         << marks[i][j] << "\t\t"
                         << (marks[i][j] >= 33 ? "Pass" : "Fail") << "\n";
                }
                cout << "--------------------------------------------\n";
                cout << "Total     : " << total[i]   << " / " << SUBJECTS * 100 << "\n";
                cout << "Percentage: " << percent[i] << " %\n";
                cout << "Grade     : " << grade[i]   << "\n";
                cout << "Result    : " << result[i]  << "\n";
                cout << "============================================\n";
            }
        }

        else if (choice == 5) {
            int rno;
            cout << "Enter Roll Number to update: "; cin >> rno;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (rollNo[i] == rno) { found = i; break; }
            }
            if (found == -1) {
                cout << "Student not found.\n";
            } else {
                int i = found;
                cout << "Re-enter marks for all subjects:\n";
                int tot = 0, fail = 0;
                for (int j = 0; j < SUBJECTS; j++) {
                    cout << "  " << sname[j] << " : "; cin >> marks[i][j];
                    if (marks[i][j] < 0)   marks[i][j] = 0;
                    if (marks[i][j] > 100)  marks[i][j] = 100;
                    if (marks[i][j] < 33) fail = 1;
                    tot += marks[i][j];
                }
                total[i]   = tot;
                percent[i] = tot / (float)SUBJECTS;

                if (fail) {
                    grade[i] = 'F'; strcpy(result[i], "Fail");
                } else if (percent[i] >= 90) {
                    grade[i] = 'A'; strcpy(result[i], "Pass");
                } else if (percent[i] >= 75) {
                    grade[i] = 'B'; strcpy(result[i], "Pass");
                } else if (percent[i] >= 60) {
                    grade[i] = 'C'; strcpy(result[i], "Pass");
                } else if (percent[i] >= 33) {
                    grade[i] = 'D'; strcpy(result[i], "Pass");
                } else {
                    grade[i] = 'F'; strcpy(result[i], "Fail");
                }
                cout << "Marks updated! New percentage: " << percent[i] << "%, Grade: " << grade[i] << "\n";
            }
        }

        else if (choice == 6) {
            int rno;
            cout << "Enter Roll Number to delete: "; cin >> rno;
            int found = -1;
            for (int i = 0; i < count; i++) {
                if (rollNo[i] == rno) { found = i; break; }
            }
            if (found == -1) {
                cout << "Student not found.\n";
            } else {
                for (int i = found; i < count - 1; i++) {
                    rollNo[i]  = rollNo[i + 1];
                    strcpy(name[i], name[i + 1]);
                    total[i]   = total[i + 1];
                    percent[i] = percent[i + 1];
                    grade[i]   = grade[i + 1];
                    strcpy(result[i], result[i + 1]);
                    for (int j = 0; j < SUBJECTS; j++)
                        marks[i][j] = marks[i + 1][j];
                }
                count--;
                cout << "Student record deleted successfully!\n";
            }
        }
        
        else if (choice == 7) {
            if (count == 0) {
                cout << "No records found.\n";
            } else {
                int top = 0;
                for (int i = 1; i < count; i++) {
                    if (percent[i] > percent[top]) top = i;
                }
                cout << "\n============================================\n";
                cout << "           CLASS TOPPER\n";
                cout << "============================================\n";
                cout << "Roll No   : " << rollNo[top]  << "\n";
                cout << "Name      : " << name[top]    << "\n";
                cout << "Total     : " << total[top]   << " / " << SUBJECTS * 100 << "\n";
                cout << "Percentage: " << percent[top] << " %\n";
                cout << "Grade     : " << grade[top]   << "\n";
                cout << "============================================\n";
            }
        }

        else if (choice != 8) {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 8);

    cout << "Exiting system. Goodbye!\n";
    return 0;
}