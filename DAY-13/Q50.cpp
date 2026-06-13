//Write a program to Find sum and average of array

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number";
    cin>>n;

    int arr[n];
    int sum = 0;
    cout<<"Enter"<<n<<"elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" ";
        cin>>arr[i];
        sum = sum + arr[i];
    }
    int avg = sum/n;

    cout<<"\nArray elements: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
        if (i<n-1)
        {
            cout<<" ";
        }
        
    }
    cout<<"\nSum = "<<sum;
    cout<<"\navg = "<<avg<<endl;

    return 0;
}