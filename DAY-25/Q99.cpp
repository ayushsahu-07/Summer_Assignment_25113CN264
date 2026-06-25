//Write a program to Sort names alphabetically.


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of names: ";
    cin >> n;

    char names[n][50], temp[50];

    cout << "Enter names:\n";
    for (int i = 0; i < n; i++)
        cin >> names[i];
  for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    cout << "Sorted names:\n";
    for (int i = 0; i < n; i++)
        cout << names[i] << "\n";

    return 0;
}