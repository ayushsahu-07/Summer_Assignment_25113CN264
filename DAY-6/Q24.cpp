//WAP to find x^n without pow()

#include<iostream>
using namespace std;

int main(){
    int x,n,result=1, i;
    cout<<"Enter a base";
    cin>>x;

    cout<<"Enter a power";
    cin>>n;

    for ( i = 0; i <=n; i++)
    {
        result = result*x;
    }
    
    cout<<"Result = "<<result;
    return 0;
}