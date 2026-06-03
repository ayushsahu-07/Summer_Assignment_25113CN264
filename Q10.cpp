//program to print prime numbers in a range

#include<iostream>
using namespace std;
int main(){
    int n, i, j;
    cout<<"Enter a number";
    cin>>n;

    cout<<"Prine numbers between 1 to "<<n<<" are as follows \n ";
    for ( j = 1; j <=n; j++)
    {
        for ( i = 2; i <=j/2; i++)
        {
            if (j%i==0)
            {
                break;
            }
        }
        if (i>j/2)
        {
            cout<<j<<" ";
        }
        
    }
     return 0;
}