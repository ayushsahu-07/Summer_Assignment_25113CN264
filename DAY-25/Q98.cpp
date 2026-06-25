//Write a program to Find common characters in strings.


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[100], s2[100];

    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int freq1[26] = {0}, freq2[26] = {0};

    for (int i = 0; i < strlen(s1); i++)
        freq1[s1[i] - 'a']++;
        
    for (int i = 0; i < strlen(s2); i++)
        freq2[s2[i] - 'a']++;

    cout << "Common characters: ";
    bool found = false;

    for (int i = 0; i < 26; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            cout << (char)(i + 'a') << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    return 0;
}

