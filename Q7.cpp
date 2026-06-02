//program to find product of digits

#include<iostream>
using namespace std;
int main(){
    int n, product=1, remainder;
    cout<<"Enter the number."<<endl;
    cin>>n;
    while (n>0)
    {
        remainder = n%10;
        product *= remainder;
        n = n/10;
    }
    cout<< "product of digit is "<< product;
    return 0;
}