//prgram to check whether a number is palindrome

#include<iostream>
using namespace std;

int main(){

    int n,n1,d,r=0;
    cout<<"Enter the number"<<endl;
    cin>>n;
    n1 = n;
    while (n>0)
    {
        d = n%10;
        r = r*10 + d;
        n = n/10;
    }
    cout<<"Actual no. is:" <<n1 <<endl;
    cout<<"Reversed no. is:" <<r <<endl;   
    
    if (r == n1)
    {
        cout<<"no. is palindrome" ;
    }
    else
    {
       cout<<" no. is not palindrome";
    }
    

    return 0;
}
