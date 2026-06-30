//Write a program to Create student record system using arrays and strings

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int rollNo[50];
    char name[50][30];
    float marks[50][5];
    int numSubjects = 5;
    int n = 0;

    int choice;

    do {
        cout << "\n----- STUDENT RECORD SYSTEM -----\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Calculate Percentage and Grade\n";
        cout << "7. Display Topper\n";
        cout << "8. Sort Students by Name\n";
        cout << "9. Sort Students by Percentage\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (n >= 50) {
                    cout << "Records full. Cannot add more students.\n";
                    break;
                }
                cout << "Enter roll number: ";
                cin >> rollNo[n];
                cout << "Enter name: ";
                cin >> name[n];
                cout << "Enter marks for " << numSubjects << " subjects:\n";
                for (int i = 0; i < numSubjects; i++) {
                    cout << "Subject " << i + 1 << ": ";
                    cin >> marks[n][i];
                }
                n++;
                cout << "Student record added successfully.\n";
                break;
            }

            case 2: {
                if (n == 0) {
                    cout << "No student records found.\n";
                    break;
                }
                cout << "\nRoll No\tName\t\tMarks\n";
                for (int i = 0; i < n; i++) {
                    cout << rollNo[i] << "\t" << name[i] << "\t\t";
                    for (int j = 0; j < numSubjects; j++) {
                        cout << marks[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 3: {
                int roll, found = 0;
                cout << "Enter roll number to search: ";
                cin >> roll;
                for (int i = 0; i < n; i++) {
                    if (rollNo[i] == roll) {
                        cout << "Student found:\n";
                        cout << "Name: " << name[i] << endl;
                        cout << "Marks: ";
                        for (int j = 0; j < numSubjects; j++) {
                            cout << marks[i][j] << " ";
                        }
                        cout << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Student with roll number " << roll << " not found.\n";
                }
                break;
            }

            case 4: {
                int roll, found = 0;
                cout << "Enter roll number: ";
                cin >> roll;
                for (int i = 0; i < n; i++) {
                    if (rollNo[i] == roll) {
                        cout << "Enter new marks for " << numSubjects << " subjects:\n";
                        for (int j = 0; j < numSubjects; j++) {
                            cout << "Subject " << j + 1 << ": ";
                            cin >> marks[i][j];
                        }
                        cout << "Marks updated successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 5: {
                int roll, found = 0;
                cout << "Enter roll number to delete: ";
                cin >> roll;
                for (int i = 0; i < n; i++) {
                    if (rollNo[i] == roll) {
                        for (int j = i; j < n - 1; j++) {
                            rollNo[j] = rollNo[j + 1];
                            strcpy(name[j], name[j + 1]);
                            for (int k = 0; k < numSubjects; k++) {
                                marks[j][k] = marks[j + 1][k];
                            }
                        }
                        n--;
                        cout << "Student record deleted successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 6: {
                int roll, found = 0;
                cout << "Enter roll number: ";
                cin >> roll;
                for (int i = 0; i < n; i++) {
                    if (rollNo[i] == roll) {
                        float total = 0;
                        for (int j = 0; j < numSubjects; j++) {
                            total += marks[i][j];
                        }
                        float percentage = total / numSubjects;
                        char grade;

                        if (percentage >= 90) grade = 'A';
                        else if (percentage >= 75) grade = 'B';
                        else if (percentage >= 60) grade = 'C';
                        else if (percentage >= 40) grade = 'D';
                        else grade = 'F';

                        cout << "Name: " << name[i] << endl;
                        cout << "Total Marks: " << total << endl;
                        cout << "Percentage: " << percentage << "%" << endl;
                        cout << "Grade: " << grade << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 7: {
                if (n == 0) {
                    cout << "No student records found.\n";
                    break;
                }
                int topperIndex = 0;
                float topperTotal = 0;

                for (int i = 0; i < n; i++) {
                    float total = 0;
                    for (int j = 0; j < numSubjects; j++) {
                        total += marks[i][j];
                    }
                    if (total > topperTotal) {
                        topperTotal = total;
                        topperIndex = i;
                    }
                }

                float topperPercentage = topperTotal / numSubjects;
                cout << "Topper: " << name[topperIndex] << endl;
                cout << "Roll Number: " << rollNo[topperIndex] << endl;
                cout << "Total Marks: " << topperTotal << endl;
                cout << "Percentage: " << topperPercentage << "%" << endl;
                break;
            }

            case 8: {
                char tempName[30];
                int tempRoll;
                float tempMarks[5];

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (strcmp(name[j], name[j + 1]) > 0) {
                            strcpy(tempName, name[j]);
                            strcpy(name[j], name[j + 1]);
                            strcpy(name[j + 1], tempName);

                            tempRoll = rollNo[j];
                            rollNo[j] = rollNo[j + 1];
                            rollNo[j + 1] = tempRoll;

                            for (int k = 0; k < numSubjects; k++) {
                                tempMarks[k] = marks[j][k];
                                marks[j][k] = marks[j + 1][k];
                                marks[j + 1][k] = tempMarks[k];
                            }
                        }
                    }
                }
                cout << "Students sorted by name successfully.\n";
                break;
            }

            case 9: {
                char tempName[30];
                int tempRoll;
                float tempMarks[5];

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        float totalJ = 0, totalJ1 = 0;
                        for (int k = 0; k < numSubjects; k++) {
                            totalJ += marks[j][k];
                            totalJ1 += marks[j + 1][k];
                        }
                        if (totalJ < totalJ1) {
                            strcpy(tempName, name[j]);
                            strcpy(name[j], name[j + 1]);
                            strcpy(name[j + 1], tempName);

                            tempRoll = rollNo[j];
                            rollNo[j] = rollNo[j + 1];
                            rollNo[j + 1] = tempRoll;

                            for (int k = 0; k < numSubjects; k++) {
                                tempMarks[k] = marks[j][k];
                                marks[j][k] = marks[j + 1][k];
                                marks[j + 1][k] = tempMarks[k];
                            }
                        }
                    }
                }
                cout << "Students sorted by percentage (descending) successfully.\n";
                break;
            }

            case 10:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 11.\n";
        }

    } while (choice != 10);

    return 0;
}
