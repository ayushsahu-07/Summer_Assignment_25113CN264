#include<iostream>
using namespace std;

int main(){
    int n, i;

    cout<<"Enter the number";
    cin>>n;
    cout<<"Factors of given number are: ";
    for ( i = 1; i <=n; i++)
    {
        if (n%i==0)
        {
            cout<<i<<endl;
        }
        
    }
    
    return 0;
}