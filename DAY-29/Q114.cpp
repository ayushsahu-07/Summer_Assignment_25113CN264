//Write a program to Create menu-driven array operations system. 

#include <iostream>
using namespace std;

int main() {
    int arr[50], n, choice, pos, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n----- ARRAY OPERATIONS MENU -----\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element (Linear Search)\n";
        cout << "5. Find Maximum\n";
        cout << "6. Find Minimum\n";
        cout << "7. Sum of Elements\n";
        cout << "8. Average of Elements\n";
        cout << "9. Reverse Array\n";
        cout << "10. Sort Array (Ascending - Bubble Sort)\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Array elements: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Enter position to insert (1 to " << n + 1 << "): ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> val;

                if (pos < 1 || pos > n + 1) {
                    cout << "Invalid position.\n";
                } else {
                    for (int i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos - 1] = val;
                    n++;
                    cout << "Element inserted successfully.\n";
                }
                break;

            case 3:
                cout << "Enter position to delete (1 to " << n << "): ";
                cin >> pos;

                if (pos < 1 || pos > n) {
                    cout << "Invalid position.\n";
                } else {
                    for (int i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    cout << "Element deleted successfully.\n";
                }
                break;

            case 4: {
                cout << "Enter element to search: ";
                cin >> val;
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == val) {
                        cout << "Element found at position " << i + 1 << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Element not found.\n";
                }
                break;
            }

            case 5: {
                int maxVal = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > maxVal) {
                        maxVal = arr[i];
                    }
                }
                cout << "Maximum element: " << maxVal << endl;
                break;
            }

            case 6: {
                int minVal = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < minVal) {
                        minVal = arr[i];
                    }
                }
                cout << "Minimum element: " << minVal << endl;
                break;
            }

            case 7: {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                cout << "Sum of elements: " << sum << endl;
                break;
            }

            case 8: {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                double avg = (double)sum / n;
                cout << "Average of elements: " << avg << endl;
                break;
            }

            case 9: {
                int start = 0, end = n - 1, temp;
                while (start < end) {
                    temp = arr[start];
                    arr[start] = arr[end];
                    arr[end] = temp;
                    start++;
                    end--;
                }
                cout << "Array reversed successfully.\n";
                break;
            }

            case 10: {
                int temp;
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                cout << "Array sorted successfully.\n";
                break;
            }

            case 11:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 11.\n";
        }

    } while (choice != 11);

    return 0;
}