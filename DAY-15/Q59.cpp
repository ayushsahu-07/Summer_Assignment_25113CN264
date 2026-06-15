//Write a program to Rotate array right.

#include<iostream>
using namespace std;

int main(){
    int n, k;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elments: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
        
    cout<<"Enter the postion to rotate right: ";
    cin>>k;

    k = k%n;

    cout<<"Original: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }
    
    for (int i = n-1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }
    
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
    
    cout<<"\nRotated right by "<<k<<" ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}