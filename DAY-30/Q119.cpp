//Write a program to Create mini employee management system. 

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int empId[100];
    char empName[100][30];
    char department[100][20];
    double salary[100];
    int experience[100];
    int n = 0;

    int choice;

    do {
        cout << "\n----- EMPLOYEE MANAGEMENT SYSTEM -----\n";
        cout << "1. Add New Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee Details\n";
        cout << "5. Delete Employee\n";
        cout << "6. Give Salary Raise\n";
        cout << "7. Search Employees by Department\n";
        cout << "8. Display Highest Paid Employee\n";
        cout << "9. Calculate Total Salary Expenditure\n";
        cout << "10. Sort Employees by Name\n";
        cout << "11. Sort Employees by Salary\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (n >= 100) {
                    cout << "Employee records full. Cannot add more.\n";
                    break;
                }
                cout << "Enter employee ID: ";
                cin >> empId[n];
                cout << "Enter name (single word, no spaces): ";
                cin >> empName[n];
                cout << "Enter department (single word, no spaces): ";
                cin >> department[n];
                cout << "Enter salary (Rs.): ";
                cin >> salary[n];
                cout << "Enter years of experience: ";
                cin >> experience[n];
                n++;
                cout << "Employee added successfully.\n";
                break;
            }

            case 2: {
                if (n == 0) {
                    cout << "No employee records found.\n";
                    break;
                }
                cout << "\nID\tName\t\tDepartment\tSalary\t\tExperience\n";
                for (int i = 0; i < n; i++) {
                    cout << empId[i] << "\t" << empName[i] << "\t\t" << department[i]
                         << "\t\t" << salary[i] << "\t\t" << experience[i] << " yrs" << endl;
                }
                break;
            }

            case 3: {
                int id, found = 0;
                cout << "Enter employee ID to search: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (empId[i] == id) {
                        cout << "Name: " << empName[i] << endl;
                        cout << "Department: " << department[i] << endl;
                        cout << "Salary: Rs. " << salary[i] << endl;
                        cout << "Experience: " << experience[i] << " yrs" << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Employee with ID " << id << " not found.\n";
                }
                break;
            }

            case 4: {
                int id, found = 0;
                cout << "Enter employee ID to update: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (empId[i] == id) {
                        cout << "Enter new name: ";
                        cin >> empName[i];
                        cout << "Enter new department: ";
                        cin >> department[i];
                        cout << "Enter new salary (Rs.): ";
                        cin >> salary[i];
                        cout << "Enter new experience (yrs): ";
                        cin >> experience[i];
                        cout << "Employee details updated successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Employee not found.\n";
                }
                break;
            }

            case 5: {
                int id, found = 0;
                cout << "Enter employee ID to delete: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (empId[i] == id) {
                        for (int j = i; j < n - 1; j++) {
                            empId[j] = empId[j + 1];
                            strcpy(empName[j], empName[j + 1]);
                            strcpy(department[j], department[j + 1]);
                            salary[j] = salary[j + 1];
                            experience[j] = experience[j + 1];
                        }
                        n--;
                        cout << "Employee deleted successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Employee not found.\n";
                }
                break;
            }

            case 6: {
                int id, found = 0;
                double raiseAmount;
                cout << "Enter employee ID for salary raise: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (empId[i] == id) {
                        cout << "Enter raise amount (Rs.): ";
                        cin >> raiseAmount;
                        salary[i] += raiseAmount;
                        cout << "Salary updated. New salary: Rs. " << salary[i] << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Employee not found.\n";
                }
                break;
            }

            case 7: {
                char dept[20];
                int any = 0;
                cout << "Enter department to search: ";
                cin >> dept;
                cout << "\nID\tName\t\tSalary\t\tExperience\n";
                for (int i = 0; i < n; i++) {
                    if (strcmp(department[i], dept) == 0) {
                        cout << empId[i] << "\t" << empName[i] << "\t\t"
                             << salary[i] << "\t\t" << experience[i] << " yrs" << endl;
                        any = 1;
                    }
                }
                if (any == 0) {
                    cout << "No employees found in department \"" << dept << "\".\n";
                }
                break;
            }

            case 8: {
                if (n == 0) {
                    cout << "No employee records found.\n";
                    break;
                }
                int highestIndex = 0;
                for (int i = 1; i < n; i++) {
                    if (salary[i] > salary[highestIndex]) {
                        highestIndex = i;
                    }
                }
                cout << "Highest Paid Employee:\n";
                cout << "ID: " << empId[highestIndex] << endl;
                cout << "Name: " << empName[highestIndex] << endl;
                cout << "Department: " << department[highestIndex] << endl;
                cout << "Salary: Rs. " << salary[highestIndex] << endl;
                break;
            }

            case 9: {
                double total = 0;
                for (int i = 0; i < n; i++) {
                    total += salary[i];
                }
                cout << "Total salary expenditure: Rs. " << total << endl;
                break;
            }

            case 10: {
                char tempName[30], tempDept[20];
                int tempId, tempExp;
                double tempSalary;

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (strcmp(empName[j], empName[j + 1]) > 0) {
                            strcpy(tempName, empName[j]);
                            strcpy(empName[j], empName[j + 1]);
                            strcpy(empName[j + 1], tempName);

                            strcpy(tempDept, department[j]);
                            strcpy(department[j], department[j + 1]);
                            strcpy(department[j + 1], tempDept);

                            tempId = empId[j];
                            empId[j] = empId[j + 1];
                            empId[j + 1] = tempId;

                            tempSalary = salary[j];
                            salary[j] = salary[j + 1];
                            salary[j + 1] = tempSalary;

                            tempExp = experience[j];
                            experience[j] = experience[j + 1];
                            experience[j + 1] = tempExp;
                        }
                    }
                }
                cout << "Employees sorted by name successfully.\n";
                break;
            }

            case 11: {
                char tempName[30], tempDept[20];
                int tempId, tempExp;
                double tempSalary;

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (salary[j] < salary[j + 1]) {
                            tempSalary = salary[j];
                            salary[j] = salary[j + 1];
                            salary[j + 1] = tempSalary;

                            strcpy(tempName, empName[j]);
                            strcpy(empName[j], empName[j + 1]);
                            strcpy(empName[j + 1], tempName);

                            strcpy(tempDept, department[j]);
                            strcpy(department[j], department[j + 1]);
                            strcpy(department[j + 1], tempDept);

                            tempId = empId[j];
                            empId[j] = empId[j + 1];
                            empId[j + 1] = tempId;

                            tempExp = experience[j];
                            experience[j] = experience[j + 1];
                            experience[j + 1] = tempExp;
                        }
                    }
                }
                cout << "Employees sorted by salary (descending) successfully.\n";
                break;
            }

            case 12:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 12.\n";
        }

    } while (choice != 12);

    return 0;
}
