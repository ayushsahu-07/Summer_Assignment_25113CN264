#include<iostream>

using namespace std;

int main(){
    int n1, n2, i;

    cout<<"Enter two numbers: ";
    cin>>n1>>n2;

    for ( i = 1; i>0; i++)
    {
        if (i%n1==0 && i%n2==0 )
        {
            cout<<"LCM = "<<i;
            break;
        } 
    }
    return 0;
}
