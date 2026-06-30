//Write a program to Create menu-driven string operations system.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    int choice;

    do {
        cout << "\n----- STRING OPERATIONS MENU -----\n";
        cout << "1. Display String Length\n";
        cout << "2. Convert to Uppercase\n";
        cout << "3. Convert to Lowercase\n";
        cout << "4. Reverse String\n";
        cout << "5. Check Palindrome\n";
        cout << "6. Count Vowels and Consonants\n";
        cout << "7. Count Words\n";
        cout << "8. Remove Spaces\n";
        cout << "9. Count Character Frequency\n";
        cout << "10. Find and Replace Character\n";
        cout << "11. Concatenate with Another String\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 11) {
            cout << "Enter a string (no spaces for option 8 onward works too): ";
            cin.ignore();
            cin.getline(str, 100);
        }

        int len = strlen(str);

        switch (choice) {
            case 1:
                cout << "Length of string: " << len << endl;
                break;

            case 2: {
                for (int i = 0; i < len; i++) {
                    if (str[i] >= 'a' && str[i] <= 'z') {
                        str[i] = str[i] - 'a' + 'A';
                    }
                }
                cout << "Uppercase: " << str << endl;
                break;
            }

            case 3: {
                for (int i = 0; i < len; i++) {
                    if (str[i] >= 'A' && str[i] <= 'Z') {
                        str[i] = str[i] - 'A' + 'a';
                    }
                }
                cout << "Lowercase: " << str << endl;
                break;
            }

            case 4: {
                char rev[100];
                for (int i = 0; i < len; i++) {
                    rev[i] = str[len - 1 - i];
                }
                rev[len] = '\0';
                cout << "Reversed string: " << rev << endl;
                break;
            }

            case 5: {
                int isPalindrome = 1;
                for (int i = 0; i < len / 2; i++) {
                    if (str[i] != str[len - 1 - i]) {
                        isPalindrome = 0;
                        break;
                    }
                }
                if (isPalindrome == 1) {
                    cout << "The string is a palindrome.\n";
                } else {
                    cout << "The string is not a palindrome.\n";
                }
                break;
            }

            case 6: {
                int vowels = 0, consonants = 0;
                for (int i = 0; i < len; i++) {
                    char ch = str[i];
                    if (ch >= 'A' && ch <= 'Z') {
                        ch = ch - 'A' + 'a';
                    }
                    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                        vowels++;
                    } else if (ch >= 'a' && ch <= 'z') {
                        consonants++;
                    }
                }
                cout << "Vowels: " << vowels << endl;
                cout << "Consonants: " << consonants << endl;
                break;
            }

            case 7: {
                int wordCount = 0;
                int inWord = 0;
                for (int i = 0; i < len; i++) {
                    if (str[i] != ' ' && inWord == 0) {
                        wordCount++;
                        inWord = 1;
                    } else if (str[i] == ' ') {
                        inWord = 0;
                    }
                }
                cout << "Number of words: " << wordCount << endl;
                break;
            }

            case 8: {
                char noSpace[100];
                int j = 0;
                for (int i = 0; i < len; i++) {
                    if (str[i] != ' ') {
                        noSpace[j] = str[i];
                        j++;
                    }
                }
                noSpace[j] = '\0';
                cout << "String without spaces: " << noSpace << endl;
                break;
            }

            case 9: {
                int freq[26] = {0};
                for (int i = 0; i < len; i++) {
                    char ch = str[i];
                    if (ch >= 'A' && ch <= 'Z') {
                        ch = ch - 'A' + 'a';
                    }
                    if (ch >= 'a' && ch <= 'z') {
                        freq[ch - 'a']++;
                    }
                }
                cout << "Character frequencies:\n";
                for (int i = 0; i < 26; i++) {
                    if (freq[i] > 0) {
                        cout << (char)('a' + i) << ": " << freq[i] << endl;
                    }
                }
                break;
            }

            case 10: {
                char findCh, replaceCh;
                cout << "Enter character to find: ";
                cin >> findCh;
                cout << "Enter character to replace with: ";
                cin >> replaceCh;

                int count = 0;
                for (int i = 0; i < len; i++) {
                    if (str[i] == findCh) {
                        str[i] = replaceCh;
                        count++;
                    }
                }
                cout << "Replaced " << count << " occurrence(s).\n";
                cout << "Updated string: " << str << endl;
                break;
            }

            case 11: {
                char str2[100];
                cout << "Enter another string to concatenate: ";
                cin.getline(str2, 100);

                char result[200];
                int i = 0, j = 0;
                for (i = 0; i < len; i++) {
                    result[i] = str[i];
                }
                int len2 = strlen(str2);
                for (j = 0; j < len2; j++) {
                    result[len + j] = str2[j];
                }
                result[len + j] = '\0';
                cout << "Concatenated string: " << result << endl;
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
