//Write a program to Create mini library system.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int bookId[100];
    char title[100][50];
    char author[100][30];
    int totalCopies[100];
    int availableCopies[100];
    int n = 0;

    int choice;

    do {
        cout << "\n----- MINI LIBRARY SYSTEM -----\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Update Book Details\n";
        cout << "8. Delete Book\n";
        cout << "9. Show Available Books Only\n";
        cout << "10. Sort Books by Title\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (n >= 100) {
                    cout << "Library full. Cannot add more books.\n";
                    break;
                }
                cout << "Enter book ID: ";
                cin >> bookId[n];
                cout << "Enter title (single word, no spaces): ";
                cin >> title[n];
                cout << "Enter author (single word, no spaces): ";
                cin >> author[n];
                cout << "Enter total copies: ";
                cin >> totalCopies[n];
                availableCopies[n] = totalCopies[n];
                n++;
                cout << "Book added successfully.\n";
                break;
            }

            case 2: {
                if (n == 0) {
                    cout << "No books in library.\n";
                    break;
                }
                cout << "\nID\tTitle\t\tAuthor\t\tTotal\tAvailable\n";
                for (int i = 0; i < n; i++) {
                    cout << bookId[i] << "\t" << title[i] << "\t\t" << author[i]
                         << "\t\t" << totalCopies[i] << "\t" << availableCopies[i] << endl;
                }
                break;
            }

            case 3: {
                int id, found = 0;
                cout << "Enter book ID to search: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (bookId[i] == id) {
                        cout << "Title: " << title[i] << endl;
                        cout << "Author: " << author[i] << endl;
                        cout << "Total Copies: " << totalCopies[i] << endl;
                        cout << "Available Copies: " << availableCopies[i] << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Book with ID " << id << " not found.\n";
                }
                break;
            }

            case 4: {
                char searchTitle[50];
                int found = 0;
                cout << "Enter title to search: ";
                cin >> searchTitle;
                for (int i = 0; i < n; i++) {
                    if (strcmp(title[i], searchTitle) == 0) {
                        cout << "Book ID: " << bookId[i] << endl;
                        cout << "Author: " << author[i] << endl;
                        cout << "Total Copies: " << totalCopies[i] << endl;
                        cout << "Available Copies: " << availableCopies[i] << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Book titled \"" << searchTitle << "\" not found.\n";
                }
                break;
            }

            case 5: {
                int id, found = 0;
                cout << "Enter book ID to issue: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (bookId[i] == id) {
                        if (availableCopies[i] > 0) {
                            availableCopies[i]--;
                            cout << "Book issued successfully.\n";
                            cout << "Remaining available copies: " << availableCopies[i] << endl;
                        } else {
                            cout << "No copies available for issue.\n";
                        }
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 6: {
                int id, found = 0;
                cout << "Enter book ID to return: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (bookId[i] == id) {
                        if (availableCopies[i] < totalCopies[i]) {
                            availableCopies[i]++;
                            cout << "Book returned successfully.\n";
                            cout << "Available copies now: " << availableCopies[i] << endl;
                        } else {
                            cout << "All copies are already in library.\n";
                        }
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 7: {
                int id, found = 0;
                cout << "Enter book ID to update: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (bookId[i] == id) {
                        cout << "Enter new title: ";
                        cin >> title[i];
                        cout << "Enter new author: ";
                        cin >> author[i];
                        cout << "Enter new total copies: ";
                        int newTotal;
                        cin >> newTotal;

                        int issued = totalCopies[i] - availableCopies[i];
                        totalCopies[i] = newTotal;
                        availableCopies[i] = newTotal - issued;
                        if (availableCopies[i] < 0) {
                            availableCopies[i] = 0;
                        }

                        cout << "Book details updated successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 8: {
                int id, found = 0;
                cout << "Enter book ID to delete: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (bookId[i] == id) {
                        for (int j = i; j < n - 1; j++) {
                            bookId[j] = bookId[j + 1];
                            strcpy(title[j], title[j + 1]);
                            strcpy(author[j], author[j + 1]);
                            totalCopies[j] = totalCopies[j + 1];
                            availableCopies[j] = availableCopies[j + 1];
                        }
                        n--;
                        cout << "Book deleted successfully.\n";
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 9: {
                int any = 0;
                cout << "\nAvailable Books:\n";
                cout << "ID\tTitle\t\tAuthor\t\tAvailable\n";
                for (int i = 0; i < n; i++) {
                    if (availableCopies[i] > 0) {
                        cout << bookId[i] << "\t" << title[i] << "\t\t" << author[i]
                             << "\t\t" << availableCopies[i] << endl;
                        any = 1;
                    }
                }
                if (any == 0) {
                    cout << "No books currently available.\n";
                }
                break;
            }

            case 10: {
                char tempTitle[50], tempAuthor[30];
                int tempId, tempTotal, tempAvail;

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (strcmp(title[j], title[j + 1]) > 0) {
                            strcpy(tempTitle, title[j]);
                            strcpy(title[j], title[j + 1]);
                            strcpy(title[j + 1], tempTitle);

                            strcpy(tempAuthor, author[j]);
                            strcpy(author[j], author[j + 1]);
                            strcpy(author[j + 1], tempAuthor);

                            tempId = bookId[j];
                            bookId[j] = bookId[j + 1];
                            bookId[j + 1] = tempId;

                            tempTotal = totalCopies[j];
                            totalCopies[j] = totalCopies[j + 1];
                            totalCopies[j + 1] = tempTotal;

                            tempAvail = availableCopies[j];
                            availableCopies[j] = availableCopies[j + 1];
                            availableCopies[j + 1] = tempAvail;
                        }
                    }
                }
                cout << "Books sorted by title successfully.\n";
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