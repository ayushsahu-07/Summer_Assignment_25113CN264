//program to find sum of digits of a number

#include<iostream>
using namespace std;

int main(){
    int n, sum =0, remainder;
    cout<< "Enter the positive number" <<endl;
    cin>> n;

    while (n>0)
    {
        remainder = n%10;
        sum +=remainder;
        n = n/10;
    }
    cout<< "Sum of digit is "<< sum;
    return 0;
}
