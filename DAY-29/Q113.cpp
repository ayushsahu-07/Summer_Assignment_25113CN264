//Write a program to Create menu-driven calculator

#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2, result;

    do {
        cout << "\n----- MENU DRIVEN CALCULATOR -----\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus (for integers)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;

            case 2:
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;

            case 3:
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;

            case 4:
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed.\n";
                } else {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                }
                break;

            case 5:
                if ((int)num2 == 0) {
                    cout << "Error: Division by zero is not allowed.\n";
                } else {
                    int a = (int)num1, b = (int)num2;
                    cout << "Result: " << (a % b) << endl;
                }
                break;

            case 6:
                cout << "Exiting the calculator. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 6.\n";
        }

    } while (choice != 6);

    return 0;
}