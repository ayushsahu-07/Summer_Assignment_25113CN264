
#include <iostream>
using namespace std;

int main() {
    int r;

    cout<<"Enter a number";
    cin>>r;

    for (int i=1; i <= r; i++) {
         for (int j = 1; j <= r - i; j++) {
            cout<<" ";
        }

        for (int j = 1; j <= (2 * i - 1); j++) {
            cout<<"*";
        }

        cout<<endl;
    }

    return 0;
}