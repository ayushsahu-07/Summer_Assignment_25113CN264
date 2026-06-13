//Write a program to Input and display array

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number";
    cin>>n;

    int arr[n];
    cout<<"Enter"<<n<<"elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" ";
        cin>>arr[i];
    }
    
    cout<<"\nArray is:\n ";
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i];
        if (i<n-1)
        {
            cout<<" ";
        }
        
    }
    cout<<endl;
    return 0;
}
