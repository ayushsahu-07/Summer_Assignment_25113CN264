//program to count digit in a number 

#include<iostream>
using namespace std;

int main(){
    int n, count=0;
    cout<<"Enter a number:";
    cin>>n;
    while (n>0)
    {
        n=n/10;
        count++;
    }
    cout<<"Number of digit in given number is:"<<count;
    return 0;
}