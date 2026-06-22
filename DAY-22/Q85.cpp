//Write a program to Check palindrome string

#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    int left = 0, right = str.length() - 1;
    int palin = 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            palin = 0;
            break;
        }
        left++;
        right--;
    }
    if (palin)
    {
        cout<<str<<" is a palindrome"<<endl;
    }
    else
    {
        cout<<str<<" is not a palindrome"<<endl;
    }
    
    return 0;
}