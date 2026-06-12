#include<iostream>
using namespace std;

int Palindrome(int n)
{

    int num = n;
    int rev = 0;
    while(n>0)
    {
        int digit = n%10;
        rev = rev*10 + digit;
        n = n/10;
    }
    return num == rev;
}

int main()
{
    int number;

    cout<<"Enter a number: ";
    cin>>number;

    if (Palindrome(number))
    {
        cout<<number<<" is a palindrome number";
    }
    else
    {
        cout<<number<<" is not palindrome number";
    }
    
    return 0;
}