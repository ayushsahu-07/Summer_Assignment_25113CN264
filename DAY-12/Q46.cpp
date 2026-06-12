//Write a program to Write function for Armstrong

#include<iostream>
#include<cmath>
using namespace std;

int armstrong(int n){
    int num = n, exp = 0, sum = 0;

    while (num>0)
    {
        exp++;
        num = num/10;
    }
    num = n;
    while (num>0)
    {
        int base = num%10;
        sum = sum + pow(base,exp);
        num = num/10;
    }
    return sum == n;
}

int main(){
    int n;

    cout<<"Enter a number: ";
    cin>>n;

    if (armstrong(n))
    {
        cout<<n<<" is an armstrong number";
    }
    else
    {
        cout<<n<<" is not an armstrong number";
    }
    
    return 0;
}