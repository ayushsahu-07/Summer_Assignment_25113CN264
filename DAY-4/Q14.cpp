//program to find nth fibonacci term

#include<iostream>
using namespace std;

int main(){
    int n, t1=0, t2=1, next_term, i;

    cout<<"Enter no. of terms:";
    cin>>n;

    if (n == 1)
    {
        cout<<n<<"st fibonacci term is: "<<t1;
    }
    else if(n==2)
    {
        cout<<n<<"nd fibonacci term is: "<< t2;
    }

    else
    {
        for ( i = 2; i <=n; i++)
        {
            next_term = t1 + t2;
            t1 = t2;
            t2 = next_term;
        }
        cout<<n<<"th fibonacci term is: "<< t2;
    }
    
    return 0;
}