#include<iostream>
using namespace std;

int main(){
    int r;

    cout<<"Enter a number";
    cin>>r;

    for (int i = 5; i >=1; i--)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
    
    return 0;
}