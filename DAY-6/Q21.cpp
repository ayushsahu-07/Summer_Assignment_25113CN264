#include<iostream>
using namespace std;

int main(){
    int n, rem, binary[50],i = 0;
    cout<<"Enter a decimal number";
    cin>>n;
    while (n>0)
    {
        rem = n%2;
        binary[i] = rem;
        n = n/2;
        i++;
    }
    
    
    cout<<"Binary form is";
    for (int j = i - 1; j>=0; j--)
    {
        cout<<binary[j];
    }
    
    return 0;
}