#include<iostream>
using namespace std;

int main(){
    int r;
    char letter = 'A';

    cout<<"Enter a number";
    cin>>r;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<letter;
        }
        cout<<endl;
        letter++;
    }
       
    return 0;
}