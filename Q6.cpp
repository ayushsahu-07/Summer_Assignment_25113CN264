//program to reverse a number

#include<iostream> 
using namespace std;

int main(){
    int n,d,r=0;
    cout<<"Enter the number" <<endl;
    cin>>n;
    while (n>0)
    {
        d = n%10;
        r = r*10 +d;
        n=n/10;
    }
    cout<<"reverse a number is "<<r;
    return 0;
}