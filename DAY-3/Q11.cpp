#include<iostream>
using namespace std;

int main(){
    int n1, n2, temp, gcd;
    cout<<"Enter the value of n1 and n2";
    cin>>n1>>n2;

    if (n1>n2)
    {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    for (int i = 1; i <= n2; i++)
    {
        if (n1%i==0 && n2%i==0)
        {
            gcd = i;
        }
    }
    cout<<gcd<<endl;
    return 0;
}