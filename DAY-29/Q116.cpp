//Write a program to Create inventory management system. 

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char itemName[50][30];
    int itemCode[50];
    int quantity[50];
    double price[50];
    int n = 0;

    int choice;

    do {
        cout << "\n----- INVENTORY MANAGEMENT SYSTEM -----\n";
        cout << "1. Add New Item\n";
        cout << "2. Display All Items\n";
        cout << "3. Search Item by Code\n";
        cout << "4. Update Item Quantity\n";
        cout << "5. Update Item Price\n";
        cout << "6. Delete Item\n";
        cout << "7. Sell Item (Reduce Stock)\n";
        cout << "8. Restock Item (Increase Stock)\n";
        cout << "9. Show Items Low on Stock (< 10)\n";
        cout << "10. Calculate Total Inventory Value\n";
        cout << "11. Sort Items by Name\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (n >= 50) {
                    cout << "Inventory full. Cannot add more items.\n";
                    break;
                }
                cout << "Enter item code: ";
                cin >> itemCode[n];
                cout << "Enter item name: ";
                cin >> itemName[n];
                cout << "Enter quantity: ";
                cin >> quantity[n];
                cout << "Enter price per unit (Rs.): ";
                cin >> price[n];
                n++;
                cout << "Item added successfully.\n";
                break;
            }

            case 2: {
                if (n == 0) {
                    cout << "Inventory is empty.\n";
                    break;
                }
                cout << "\nCode\tName\t\tQuantity\tPrice(Rs.)\n";
                for (int i = 0; i < n; i++) {
                    cout << itemCode[i] << "\t" << itemName[i] << "\t\t"
                         << quantity[i] << "\t\t" << price[i] << endl;
                }
                break;
            }

            case 3: {
                int code, found = 0;
                cout << "Enter item code to search: ";
                cin >> code;
                for (int i = 0; i < n; i++) {
                    if (itemCode[i] == code) {
                        cout << "Item found:\n";
                        cout << "Name: " << itemName[i] << endl;
                        cout << "Quantity: " << quantity[i] << endl;
                        cout << "Price: Rs. " << price[i] << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Item with code " << code << " not found.\n";
                }
                break;
            }

            case 4: {
                int code, newQty, found = 0;
                cout << "Enter item code: ";
                cin >> code;
                for (int i = 0; i < n; i++) {
                    if (itemCode[i] == code) {
                        cout << "Enter new quantity: ";
                        cin >> newQty;
                        quantity[i] = newQty;
                        cout << "Quantity updated successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Item not found.\n";
                }
                break;
            }

            case 5: {
                int code, found = 0;
                double newPrice;
                cout << "Enter item code: ";
                cin >> code;
                for (int i = 0; i < n; i++) {
                    if (itemCode[i] == code) {
                        cout << "Enter new price (Rs.): ";
                        cin >> newPrice;
                        price[i] = newPrice;
                        cout << "Price updated successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Item not found.\n";
                }
                break;
            }

            case 6: {
                int code, found = 0;
                cout << "Enter item code to delete: ";
                cin >> code;
                for (int i = 0; i < n; i++) {
                    if (itemCode[i] == code) {
                        for (int j = i; j < n - 1; j++) {
                            itemCode[j] = itemCode[j + 1];
                            strcpy(itemName[j], itemName[j + 1]);
                            quantity[j] = quantity[j + 1];
                            price[j] = price[j + 1];
                        }
                        n--;
                        cout << "Item deleted successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Item not found.\n";
                }
                break;
            }

            case 7: {
                int code, sellQty, found = 0;
                cout << "Enter item code to sell: ";
                cin >> code;
                for (int i = 0; i < n; i++) {
                    if (itemCode[i] == code) {
                        cout << "Enter quantity to sell: ";
                        cin >> sellQty;
                        if (sellQty > quantity[i]) {
                            cout << "Insufficient stock. Available: " << quantity[i] << endl;
                        } else {
                            quantity[i] -= sellQty;
                            cout << "Sold " << sellQty << " units of " << itemName[i] << endl;
                            cout << "Remaining stock: " << quantity[i] << endl;
                        }
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Item not found.\n";
                }
                break;
            }

            case 8: {
                int code, restockQty, found = 0;
                cout << "Enter item code to restock: ";
                cin >> code;
                for (int i = 0; i < n; i++) {
                    if (itemCode[i] == code) {
                        cout << "Enter quantity to add: ";
                        cin >> restockQty;
                        quantity[i] += restockQty;
                        cout << "Stock updated. New quantity: " << quantity[i] << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Item not found.\n";
                }
                break;
            }

            case 9: {
                int any = 0;
                cout << "\nItems low on stock (less than 10 units):\n";
                for (int i = 0; i < n; i++) {
                    if (quantity[i] < 10) {
                        cout << itemCode[i] << "\t" << itemName[i] << "\t\tQty: " << quantity[i] << endl;
                        any = 1;
                    }
                }
                if (any == 0) {
                    cout << "No items are low on stock.\n";
                }
                break;
            }

            case 10: {
                double total = 0;
                for (int i = 0; i < n; i++) {
                    total += quantity[i] * price[i];
                }
                cout << "Total inventory value: Rs. " << total << endl;
                break;
            }

            case 11: {
                char tempName[30];
                int tempCode;
                int tempQty;
                double tempPrice;

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (strcmp(itemName[j], itemName[j + 1]) > 0) {
                            strcpy(tempName, itemName[j]);
                            strcpy(itemName[j], itemName[j + 1]);
                            strcpy(itemName[j + 1], tempName);

                            tempCode = itemCode[j];
                            itemCode[j] = itemCode[j + 1];
                            itemCode[j + 1] = tempCode;

                            tempQty = quantity[j];
                            quantity[j] = quantity[j + 1];
                            quantity[j + 1] = tempQty;

                            tempPrice = price[j];
                            price[j] = price[j + 1];
                            price[j + 1] = tempPrice;
                        }
                    }
                }
                cout << "Items sorted by name successfully.\n";
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