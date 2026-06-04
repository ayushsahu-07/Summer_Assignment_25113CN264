//program to find factorial of number

#include<iostream>
using namespace std;

int main(){

    int n, fact = 1,i;
    
    cout<<"enter the number";
    cin>>n;

    for (i=1; i<n; i++)
    {
       fact*=i;
    }
    cout<<"Result: "<<fact;
    return 0;
}
