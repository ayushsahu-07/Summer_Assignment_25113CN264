#include<iostream>
using namespace std;
int main()
{
    int i,n,sum = 0;
    cout<<"Enter Nth number";
    cin>>n;
    for (i = 1; i <=n; i++)
    {
        sum+=i;
    }
    cout<<"sum of "<<n<<"numbers:"<<sum;
    return 0;    
}   