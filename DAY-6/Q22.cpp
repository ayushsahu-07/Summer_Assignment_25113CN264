//WAP to binary to decimal

#include<iostream>
using namespace std;

int main(){
    int n, digit, decimal = 0, base = 1;

    cout<<"Enter a number";
    cin>>n;

    while (n>0)
    {
        digit = n%10;
        decimal = decimal + digit*base;
        base = base*2;
        n = n/10;
    }
    
    cout<<"Decimal number is:" << decimal;
    return 0;
}