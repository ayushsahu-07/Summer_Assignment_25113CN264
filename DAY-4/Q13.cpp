//program to generate fibonacci series

#include<iostream>
using namespace std;

int main(){
    int t1 = 0, t2 = 1, next_term, n, i;

    cout<<"Enter no. of terms";
    cin>>n;

    cout<< t1 << "\n" << t2 <<"\n"  ;
    for ( i = 2; i <= n; i++)
    {
        next_term = t1 + t2;
        cout<< next_term<<"\n";
        t1 = t2;
        t2 = next_term;
    }
    
    return 0;
}