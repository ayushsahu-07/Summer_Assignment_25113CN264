//program to check perfect program

#include<iostream>
using namespace std;

int main(){
    int n, i, k=0; 
    cout<<"Enter a number";
    cin>>n;

    for ( i = 1; i <n; i++)
    {
        if (n%i==0)
        {
            k=k+i;
        }
        
    }
    if (k==n)
    {
        cout<<n<<" is a perfect number";
    }
    else
    {
        cout<<n<<" is not a perfect number";
    }
    
    return 0;
}