//a program to Print Armstrong numbers in range 


#include<iostream>
using namespace std;
int main(){
   int i, n, num, r, sum=0;
   cout<<"Enter a number";
   cin>>num;
   cout<<"Armstrong numbers are:";
   for ( i = 1; i <=num; i++)
   {
    sum=0;
    n=i;
    while (n!=0)
    {
        r = n%10;
        sum = sum + (r*r*r);
        n = n/10;
    }
    if (i == sum)
    {
        cout<<i<<" ";
    }
    
   }
   
    return 0;
}