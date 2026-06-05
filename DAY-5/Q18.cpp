#include<iostream>
using namespace std;

int main(){
    int N, E, f, sum =0, rem;
    cout<<"Enter the number";
    cin>>N;
    E=N;
    while (N>0)
    {
        rem = N%10;
        f =1;
        for (int i = 1; i <=rem; i++)
        {
            f = f*i;
        }
        sum=sum+f;
        N=N/10;
    }
     if (E==sum)
     {
        cout<<"It is strong number";
     }
     else {
        cout<<"It is not a strong number";
     }
     

    return 0;
}