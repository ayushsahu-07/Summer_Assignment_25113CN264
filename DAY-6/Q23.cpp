//WAP to count set bits in  a number

#include<iostream>
using namespace std;

int main(){
    int n, count = 0;

    cout<<"Enter a number";
    cin>>n;

    while (n > 0)
    {
        if (n%2==1)
        {
            count++;
        }
        n=n/2;
    }
    cout<<"Number of set bits = "<<count;
    return 0;
}