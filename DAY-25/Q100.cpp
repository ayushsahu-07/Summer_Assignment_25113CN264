//Write a program to Sort words by length.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    char words[n][50], temp[50];

    cout << "Enter words:\n";
    for (int i = 0; i < n; i++)
        cin >> words[i];

for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    cout << "Words sorted by length:\n";
    for (int i = 0; i < n; i++)
        cout << words[i] << " (length = " << strlen(words[i]) << ")\n";

    return 0;
}