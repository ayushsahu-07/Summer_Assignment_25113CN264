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

        for (char ch = 'A'; ch<'A'+i; ch++)
        {
            cout<<ch;
        }
        
        for (char ch = 'A' + i - 2; ch >= 'A'; ch--) {
            cout<<ch;
        }

        cout<<endl;
    }

    return 0;
}