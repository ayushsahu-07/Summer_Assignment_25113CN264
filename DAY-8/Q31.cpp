#include<iostream>
using namespace std;

int main(){
    int r;

    cout<<"Enter a number";
    cin>>r;

    for (int i = 1; i <=r; i++)
    {
        for (char ch = 'A'; ch<'A'+i; ch++)
        {
            cout<<ch;
        }
        cout<<endl;
    }
    
    return 0;
}