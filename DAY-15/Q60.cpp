//Write a program to Move zeroes to end

#include<iostream>
using namespace std;

int main(){
    int n, pos = 0;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != 0){
            arr[pos++] = arr[i];
        }
    }
    while (pos<n)
    {
        arr[pos++] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}