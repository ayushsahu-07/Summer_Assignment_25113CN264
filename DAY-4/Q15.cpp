//program to check armstrong number 

#include<iostream>
using namespace std;
int main(){
    int n, n1, rem, sum=0;
    cout<<"Enter the number: ";
    cin>>n;
    n1 = n;
    while (n1!=0)
    {
       rem = n1%10;
       sum = sum +(rem*rem*rem);
       n1 = n1/10;
    }

    if (sum==n)
    {
        cout<<"it is armstrong number";
    }
    else
    {
        cout<<"It is not armstrong number";
    }
    
    
    return 0;
}