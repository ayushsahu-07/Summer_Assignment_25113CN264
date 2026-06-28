//Write a program to Create library management system


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX = 100;

    char title[MAX][50], author[MAX][50];
    int  bookId[MAX], qty[MAX];
    int  totalBooks = 0;

    char mName[MAX][50];
    int  mId[MAX];
    int  totalMembers = 0;

    int  issueBook[MAX], issueMember[MAX];
    int  totalIssues = 0;

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Add Member\n";
        cout << "5. Display All Members\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Display All Issues\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (totalBooks >= MAX) {
                cout << "Library full!\n";
            } else {
                cout << "Enter Book ID   : "; cin >> bookId[totalBooks];
                cout << "Enter Title     : "; cin.ignore(); cin.getline(title[totalBooks], 50);
                cout << "Enter Author    : "; cin.getline(author[totalBooks], 50);
                cout << "Enter Quantity  : "; cin >> qty[totalBooks];
                cout << "Book added successfully!\n";
                totalBooks++;
            }
        }

        else if (choice == 2) {
            if (totalBooks == 0) {
                cout << "No books in library.\n";
            } else {
                cout << "\n--- Book List ---\n";
                cout << "ID\tQty\tTitle\t\t\tAuthor\n";
                cout << "-------------------------------------------\n";
                for (int i = 0; i < totalBooks; i++) {
                    cout << bookId[i] << "\t"
                         << qty[i]    << "\t"
                         << title[i]  << "\t\t"
                         << author[i] << "\n";
                }
            }
        }

        else if (choice == 3) {
            int sid;
            cout << "Enter Book ID to search: "; cin >> sid;
            int found = 0;
            for (int i = 0; i < totalBooks; i++) {
                if (bookId[i] == sid) {
                    cout << "\nBook Found!\n";
                    cout << "ID     : " << bookId[i] << "\n";
                    cout << "Title  : " << title[i]  << "\n";
                    cout << "Author : " << author[i] << "\n";
                    cout << "Qty    : " << qty[i]    << "\n";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }

        else if (choice == 4) {
            if (totalMembers >= MAX) {
                cout << "Member list full!\n";
            } else {
                cout << "Enter Member ID   : "; cin >> mId[totalMembers];
                cout << "Enter Member Name : "; cin.ignore(); cin.getline(mName[totalMembers], 50);
                cout << "Member added successfully!\n";
                totalMembers++;
            }
        }

        else if (choice == 5) {
            if (totalMembers == 0) {
                cout << "No members registered.\n";
            } else {
                cout << "\n--- Member List ---\n";
                cout << "ID\tName\n";
                cout << "-------------------\n";
                for (int i = 0; i < totalMembers; i++) {
                    cout << mId[i] << "\t" << mName[i] << "\n";
                }
            }
        }

        else if (choice == 6) {
            int bid, mid;
            cout << "Enter Book ID   : "; cin >> bid;
            cout << "Enter Member ID : "; cin >> mid;

            int bi = -1;
            for (int i = 0; i < totalBooks; i++)
                if (bookId[i] == bid) { bi = i; break; }

            int mi = -1;
            for (int i = 0; i < totalMembers; i++)
                if (mId[i] == mid) { mi = i; break; }

            if (bi == -1)       cout << "Book not found.\n";
            else if (mi == -1)  cout << "Member not found.\n";
            else if (qty[bi] <= 0) cout << "Book not available (qty = 0).\n";
            else {
                qty[bi]--;
                issueBook[totalIssues]   = bid;
                issueMember[totalIssues] = mid;
                totalIssues++;
                cout << "Book issued successfully!\n";
            }
        }

        else if (choice == 7) {
            int bid, mid;
            cout << "Enter Book ID   : "; cin >> bid;
            cout << "Enter Member ID : "; cin >> mid;

            int found = 0;
            for (int i = 0; i < totalIssues; i++) {
                if (issueBook[i] == bid && issueMember[i] == mid) {
                    for (int j = i; j < totalIssues - 1; j++) {
                        issueBook[j]   = issueBook[j+1];
                        issueMember[j] = issueMember[j+1];
                    }
                    totalIssues--;

                    for (int k = 0; k < totalBooks; k++) {
                        if (bookId[k] == bid) { qty[k]++; break; }
                    }
                    cout << "Book returned successfully!\n";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "No matching issue record found.\n";
        }

        else if (choice == 8) {
            if (totalIssues == 0) {
                cout << "No books currently issued.\n";
            } else {
                cout << "\n--- Issue Records ---\n";
                cout << "Book ID\tMember ID\n";
                cout << "-------------------\n";
                for (int i = 0; i < totalIssues; i++) {
                    cout << issueBook[i] << "\t" << issueMember[i] << "\n";
                }
            }
        }

        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    cout << "Exiting... Goodbye!\n";
    return 0;
}