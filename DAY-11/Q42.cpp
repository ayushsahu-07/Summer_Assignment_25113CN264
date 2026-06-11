//WAP to write function to find maximum

#include<iostream>
using namespace std;

int Max(int a, int b){
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(){
    int n1, n2;
    cout<<"Enter two numbers:";
    cin>>n1>>n2;

    cout<<"Maximum Number = "<<Max(n1, n2);
    
    return 0;
}