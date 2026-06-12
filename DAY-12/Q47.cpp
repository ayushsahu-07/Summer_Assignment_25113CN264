//Write a program to Write function for Fibonacci

#include<iostream>
using namespace std;

void fib(int n){
    int n1, n2, next;
    n1 = 0;
    n2 = 1;

    cout<<"Fibonacci Series: ";
    for (int i = 0; i < n; i++)
    {
        cout<<n1<<" ";

        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }

}

int main(){
    int n;
    cout<<"Enter a number";
    cin>>n;

    fib(n);
    return 0;
}