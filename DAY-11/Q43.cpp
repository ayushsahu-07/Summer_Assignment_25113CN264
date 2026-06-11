//WAP to write function to check prime

#include<iostream>
using namespace std;

int Prime(int n){
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <=n/2; i++)
    {
        if (n%i==0)
        {
            return false;
        }
        
    }
    return true;
}

int main(){
    int num;
    cout<<"Enter a number:";
    cin>>num;
    if (Prime(num))
    {
        cout<<"The number is prime."<<endl;
    }
    else
    {
        cout<<"The number is not prime."<<endl;
    }
    
    return 0;
}