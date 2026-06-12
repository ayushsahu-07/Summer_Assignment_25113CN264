//Write a program to Write function for perfect number

#include<iostream>
using namespace std;

int Perfect(int n){
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n%i == 0)
        {
            sum = sum+i;
        }
        
    }
    return sum == n;
}

int main(){
    int n;

    cout<<"Enter a number";
    cin>>n;

    if (Perfect(n))
    {
        cout<<n<<" is a perfect number.";
    }
    else
    {
        cout<<n<<" is not a perfect number.";
    }
    
    return 0;
}