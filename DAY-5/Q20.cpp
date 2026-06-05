//program to find largest prime factor

#include<iostream>
using namespace std;

int main(){
    int n, largest_prime=1, i;
    cout<<"Enter a number";
    cin>>n;

    for ( i = 2; i <=n; i++)
    {
        while (n%i==0)
        {
            largest_prime = i;
            n= n/i;
        }
       
    }
     cout<<"Largest Prime Factor = "<<largest_prime;
    
    return 0;
}