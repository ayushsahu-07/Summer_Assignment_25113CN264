//Write a program to Create contact management system.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX = 100;

    int  cId[MAX];
    char cName[MAX][50];
    char cPhone[MAX][15];
    char cEmail[MAX][50];
    char cCity[MAX][30];
    char cGroup[MAX][20];   
    int  totalContacts = 0;
    int  nextId = 1;

    int choice;

    do {
        cout << "\n====== CONTACT MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by Phone\n";
        cout << "5. Update Contact\n";
        cout << "6. Delete Contact\n";
        cout << "7. Display by Group\n";
        cout << "8. Sort Contacts by Name\n";
        cout << "9. Count Contacts\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (totalContacts >= MAX) {
                cout << "Contact list full!\n";
            } else {
                char tempPhone[15];
                cin.ignore();
                cout << "Enter Name        : "; cin.getline(cName[totalContacts], 50);
                cout << "Enter Phone       : "; cin.getline(tempPhone, 15);

                int dup = 0;
                for (int i = 0; i < totalContacts; i++)
                    if (strcmp(cPhone[i], tempPhone) == 0) { dup = 1; break; }

                if (dup) {
                    cout << "Phone number already exists!\n";
                } else {
                    strcpy(cPhone[totalContacts], tempPhone);
                    cout << "Enter Email       : "; cin.getline(cEmail[totalContacts], 50);
                    cout << "Enter City        : "; cin.getline(cCity[totalContacts], 30);
                    cout << "Group (1-Family / 2-Friend / 3-Work / 4-Other): ";
                    int g; cin >> g;
                    if      (g == 1) strcpy(cGroup[totalContacts], "Family");
                    else if (g == 2) strcpy(cGroup[totalContacts], "Friend");
                    else if (g == 3) strcpy(cGroup[totalContacts], "Work");
                    else             strcpy(cGroup[totalContacts], "Other");

                    cId[totalContacts] = nextId++;
                    totalContacts++;
                    cout << "Contact added successfully! ID: " << cId[totalContacts-1] << "\n";
                }
            }
        }

        else if (choice == 2) {
            if (totalContacts == 0) {
                cout << "No contacts found.\n";
            } else {
                cout << "\n--- All Contacts ---\n";
                cout << "ID\tName\t\tPhone\t\tEmail\t\t\tCity\t\tGroup\n";
                cout << "--------------------------------------------------------------------------------------------\n";
                for (int i = 0; i < totalContacts; i++) {
                    cout << cId[i]    << "\t"
                         << cName[i]  << "\t\t"
                         << cPhone[i] << "\t\t"
                         << cEmail[i] << "\t\t"
                         << cCity[i]  << "\t\t"
                         << cGroup[i] << "\n";
                }
            }
        }

        else if (choice == 3) {
            char sname[50];
            cin.ignore();
            cout << "Enter Name to search: "; cin.getline(sname, 50);

            int found = 0;
            cout << "\n--- Search Results ---\n";
            for (int i = 0; i < totalContacts; i++) {
                if (strstr(cName[i], sname) != NULL) {
                    cout << "ID    : " << cId[i]    << "\n";
                    cout << "Name  : " << cName[i]  << "\n";
                    cout << "Phone : " << cPhone[i] << "\n";
                    cout << "Email : " << cEmail[i] << "\n";
                    cout << "City  : " << cCity[i]  << "\n";
                    cout << "Group : " << cGroup[i] << "\n";
                    cout << "----------------------\n";
                    found = 1;
                }
            }
            if (!found) cout << "No contact found with that name.\n";
        }

        else if (choice == 4) {
            char sphone[15];
            cin.ignore();
            cout << "Enter Phone to search: "; cin.getline(sphone, 15);

            int found = 0;
            for (int i = 0; i < totalContacts; i++) {
                if (strcmp(cPhone[i], sphone) == 0) {
                    cout << "\n--- Contact Found ---\n";
                    cout << "ID    : " << cId[i]    << "\n";
                    cout << "Name  : " << cName[i]  << "\n";
                    cout << "Phone : " << cPhone[i] << "\n";
                    cout << "Email : " << cEmail[i] << "\n";
                    cout << "City  : " << cCity[i]  << "\n";
                    cout << "Group : " << cGroup[i] << "\n";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "No contact found with that phone number.\n";
        }

        else if (choice == 5) {
            int uid;
            cout << "Enter Contact ID to update: "; cin >> uid;

            int ui = -1;
            for (int i = 0; i < totalContacts; i++)
                if (cId[i] == uid) { ui = i; break; }

            if (ui == -1) {
                cout << "Contact not found!\n";
            } else {
                cout << "\nCurrent Details:\n";
                cout << "Name  : " << cName[ui]  << "\n";
                cout << "Phone : " << cPhone[ui] << "\n";
                cout << "Email : " << cEmail[ui] << "\n";
                cout << "City  : " << cCity[ui]  << "\n";
                cout << "Group : " << cGroup[ui] << "\n";

                int uc;
                cout << "\nWhat to update?\n";
                cout << "1.Name  2.Phone  3.Email  4.City  5.Group\n";
                cout << "Enter choice: "; cin >> uc;
                cin.ignore();

                if (uc == 1) {
                    cout << "New Name  : "; cin.getline(cName[ui], 50);
                    cout << "Name updated!\n";
                }
                else if (uc == 2) {
                    char np[15];
                    cout << "New Phone : "; cin.getline(np, 15);
                    int dup = 0;
                    for (int i = 0; i < totalContacts; i++)
                        if (i != ui && strcmp(cPhone[i], np) == 0) { dup = 1; break; }
                    if (dup) cout << "Phone already used by another contact!\n";
                    else { strcpy(cPhone[ui], np); cout << "Phone updated!\n"; }
                }
                else if (uc == 3) {
                    cout << "New Email : "; cin.getline(cEmail[ui], 50);
                    cout << "Email updated!\n";
                }
                else if (uc == 4) {
                    cout << "New City  : "; cin.getline(cCity[ui], 30);
                    cout << "City updated!\n";
                }
                else if (uc == 5) {
                    cout << "New Group (1-Family/2-Friend/3-Work/4-Other): ";
                    int g; cin >> g;
                    if      (g == 1) strcpy(cGroup[ui], "Family");
                    else if (g == 2) strcpy(cGroup[ui], "Friend");
                    else if (g == 3) strcpy(cGroup[ui], "Work");
                    else             strcpy(cGroup[ui], "Other");
                    cout << "Group updated!\n";
                }
                else cout << "Invalid update choice!\n";
            }
        }

        else if (choice == 6) {
            int did;
            cout << "Enter Contact ID to delete: "; cin >> did;

            int di = -1;
            for (int i = 0; i < totalContacts; i++)
                if (cId[i] == did) { di = i; break; }

            if (di == -1) {
                cout << "Contact not found!\n";
            } else {
                cout << "Deleting: " << cName[di] << " (" << cPhone[di] << ")\n";
                for (int i = di; i < totalContacts - 1; i++) {
                    cId[i] = cId[i+1];
                    strcpy(cName[i],  cName[i+1]);
                    strcpy(cPhone[i], cPhone[i+1]);
                    strcpy(cEmail[i], cEmail[i+1]);
                    strcpy(cCity[i],  cCity[i+1]);
                    strcpy(cGroup[i], cGroup[i+1]);
                }
                totalContacts--;
                cout << "Contact deleted successfully!\n";
            }
        }

        else if (choice == 7) {
            int gc;
            cout << "Select Group (1-Family/2-Friend/3-Work/4-Other): "; cin >> gc;
            char gname[20];
            if      (gc == 1) strcpy(gname, "Family");
            else if (gc == 2) strcpy(gname, "Friend");
            else if (gc == 3) strcpy(gname, "Work");
            else              strcpy(gname, "Other");

            cout << "\n--- Group: " << gname << " ---\n";
            int found = 0;
            for (int i = 0; i < totalContacts; i++) {
                if (strcmp(cGroup[i], gname) == 0) {
                    cout << "ID    : " << cId[i]    << "\n";
                    cout << "Name  : " << cName[i]  << "\n";
                    cout << "Phone : " << cPhone[i] << "\n";
                    cout << "Email : " << cEmail[i] << "\n";
                    cout << "City  : " << cCity[i]  << "\n";
                    cout << "----------------------\n";
                    found = 1;
                }
            }
            if (!found) cout << "No contacts in this group.\n";
        }

        else if (choice == 8) {
            if (totalContacts < 2) {
                cout << "Not enough contacts to sort.\n";
            } else {
                for (int i = 0; i < totalContacts - 1; i++) {
                    for (int j = 0; j < totalContacts - i - 1; j++) {
                        if (strcmp(cName[j], cName[j+1]) > 0) {
                            // swap all fields
                            int ti = cId[j]; cId[j] = cId[j+1]; cId[j+1] = ti;

                            char tmp[50];
                            strcpy(tmp, cName[j]);  strcpy(cName[j],  cName[j+1]);  strcpy(cName[j+1],  tmp);
                            strcpy(tmp, cEmail[j]); strcpy(cEmail[j], cEmail[j+1]); strcpy(cEmail[j+1], tmp);
                            strcpy(tmp, cGroup[j]); strcpy(cGroup[j], cGroup[j+1]); strcpy(cGroup[j+1], tmp);

                            char tmp2[30];
                            strcpy(tmp2, cCity[j]);  strcpy(cCity[j],  cCity[j+1]);  strcpy(cCity[j+1],  tmp2);

                            char tmp3[15];
                            strcpy(tmp3, cPhone[j]); strcpy(cPhone[j], cPhone[j+1]); strcpy(cPhone[j+1], tmp3);
                        }
                    }
                }
                cout << "Contacts sorted by name (A → Z)!\n";
            }
        }

        else if (choice == 9) {
            int fam = 0, fri = 0, wrk = 0, oth = 0;
            for (int i = 0; i < totalContacts; i++) {
                if      (strcmp(cGroup[i], "Family") == 0) fam++;
                else if (strcmp(cGroup[i], "Friend") == 0) fri++;
                else if (strcmp(cGroup[i], "Work")   == 0) wrk++;
                else                                        oth++;
            }
            cout << "\n--- Contact Count ---\n";
            cout << "Total   : " << totalContacts << "\n";
            cout << "Family  : " << fam << "\n";
            cout << "Friend  : " << fri << "\n";
            cout << "Work    : " << wrk << "\n";
            cout << "Other   : " << oth << "\n";
        }

        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
 