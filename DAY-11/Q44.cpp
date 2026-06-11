//WAP to write function to find factorial

#include<iostream>
using namespace std;

int Fact(int n){
    int Fact = 1;
    for (int i = 1; i <= n; i++)
    {
        Fact*=i;
    }
    return Fact;
}

int main(){
    int num;

    cout<<"Enter a number:";
    cin>>num;

    cout<<"Factorial of "<<num<<" is "<< Fact(num)<<endl;
    return 0;
}